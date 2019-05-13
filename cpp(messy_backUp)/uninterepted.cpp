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
#define clean(sum,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1510
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,int> PR;

LL sum[MAX][MAX], n, m, dp[MAX][MAX];
PR dude[MAX];

LL rec()
{
    FOR(i,1,n) FOR(j,0,m) dp[i][j] = minn;
    dp[0][0] = minn;

    FOR(p,0,n-1)
    {
        LL c = 0;

        FOR(i,0,m-1)
        {
            c += sum[p][i];

            int l = 0, r = m - 1;
            if(p%2 == 0) r = i - 1;
            else l = i + 1;

            FOR(j,l,r) dp[p + 1][j] = max(dp[p + 1][j], c + dp[p][i]);
        }
    }

    LL ret;

    FOR(i,0,m-1)
    {
        if(i == 0) ret = dp[n][i];
        else ret = max(ret, dp[n][i]);
    }

    return ret;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n >> m;
    FOR(i,0,n-1)
    FOR(j,0,m-1) cin >> sum[i][j];

    cout << rec() << endl;

    return 0;
}

