#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 310
#define MP make_pair
#define sz(p) (int)mat[p].size()
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,int> PR;

int n, c;
string str[MAX];
PR ara[MAX];

PR hashVal(string str)
{
    LL ret = 0, ba = 1;

    for(auto ch : str)
    {
        LL x = ch - 'a'; x++;
        ret += (x * ba);
        ba *= 31;
    }

    return MP(ret, str.size());
}

vector< pair<int, int> > mat[MAX];
int dp[MAX][MAX];

int solve()
{
    FOR(pos,0,n-1)
        for(auto x : mat[pos])
            FOR(i,0,n-1)
            {
                 if(!i)  dp[pos][i + 1] = max(dp[pos][i + 1], x.S);
                 else dp[pos][i + 1] = max(dp[pos][i + 1], min(dp[x.F][i], x.S));
            }

    int ret = 0;
    FOR(i,0,n)
        FOR(j,0,n)
            ret = max(ret, dp[i][j] * (j + 1));

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int prin = 0;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str[i];
        ara[i] = hashVal( str[i] );
        c += ara[i].S;
        if(i != n-1) c++;
        ///cout << ara[i].F << ' ' << ara[i].S << endl;
    }
    ///cout << c << endl;

    FOR(i,0,n-1)
    {
        FOR(j,i+1,n-1)
        {
            int x = i, y = j, z = 0;
            while(x < j && y < n)
            {
                if(str[x] == str[y])
                {
                    if(x != i) z++;
                    z += (ara[x].S - 1);
                }
                else break;

                x++;
                y++;
            }
            mat[j].PB(MP(i, z));
        }
    }

    cout << c - solve() << endl;

    return 0;
}

