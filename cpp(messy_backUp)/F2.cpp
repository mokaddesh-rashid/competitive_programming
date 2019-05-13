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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()8
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define M               (long long) (1e15)
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

map<int,int> mopa;
int getID(int v)
{
    if(mopa[v] == 0) mopa[v] = mopa.size();
    return mopa[v];
}

int cnt[MAX];
void in(int v)
{
    v = getID( v );
    cnt[v]++;
}
vector<int> ara;
int dp[20][MAX];

int rec(int p,int lastV)
{
    if(p == 19) return 0;

    int &temp = dp[p][lastV];
    if(temp != -1) return temp;

    temp = rec(p + 1, lastV);
    if(ara[p] >= lastV)
    {
        temp = max(lastV, temp);
        if(lastV % 2 == 0)
            temp = max(lastV + rec(p + 1, (lastV / 2)), temp);
    }
    return temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n, v;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> v;
        in( v );
    }
    FOR(i,0,n)
        if(cnt[i]) ara.PB( cnt[i] );

    sort(ara.begin(), ara.end());
    reverse(ara.begin(), ara.end());

    ara.resize( 19 );

    int prin = 0; mem(dp, -1);
    FOR(i,0,ara[0])
        prin = max(prin, rec(0, i));

    cout << prin << endl;

    return 0;
}

