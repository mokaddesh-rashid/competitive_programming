#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ULL unsigned long long
#define MAX 100010
#define MP make_pair
#define F first
#define S second
#define Ba 29

typedef pair<ULL,int> PR;

PR ar[MAX];
string pattern[MAX], text;
int n, m;
ULL mul[MAX];
ULL fin[MAX];
vector<int> mat[MAX], co[MAX];
map<ULL,int> mopa;

void up()
{
    ULL x = 1;
    FOR(i,0,1000)
    {
        mul[i] = x;
        x *= Ba;
    }
}
int ID(char ch)
{
    int ret = 0;

    if(ch < 'a') ret = ch - 'A';
    else ret = ch - 'a';

    return ret + 1;
}

int dp[MAX];
int rec(int p)
{
    if(p == n) return 1;

    if(dp[p] != -1) return dp[p];

    dp[p] = 0;
    for(auto go : mat[p])
    dp[p] = max(dp[p], rec( go ));

    return dp[p];
}

void prin(int p)
{
    if(p == n) return;

    int l = 0;
    for(auto go : mat[p])
    {
        if(rec(go))
        {
            cout << pattern[ co[p][l] ] << ' ';
            prin( go );
            return;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    up();
    cin >> n >> text >> m;
    FOR(i,0,m-1) cin >> pattern[i];

    FOR(i,0,m-1)
    {
        int sz = pattern[i].size();

        reverse(pattern[i].begin(), pattern[i].end());
        ULL c = 0, x = 1;
        FOR(j,0,sz-1)
        {
            ULL d = ID( pattern[i][j] );
            c += ( d * mul[j] );
        }
        ar[i] = MP(c, i);
        reverse(pattern[i].begin(), pattern[i].end());
    }
    sort(ar, ar + m);
    FOR(i,0,m-1) fin[i] = ar[i].F;

    FOR(i,0,n-1)
    {
        ULL c = 0;
        int x = 0;

        FOR(j,0,1000)
        {
            if(i + j == n) break;
            ULL d = ID(text[i + j]);
            c += (d * mul[j]);

            x = lower_bound(fin, fin + m, c) - fin;
            if(fin[x] == c)
            {
                mat[i].push_back(i + j + 1); co[i].push_back( ar[x].S );
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    prin(0);
    return 0;
}
