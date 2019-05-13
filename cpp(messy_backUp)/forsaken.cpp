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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define sz(p) (int)mat[p].size()
typedef pair<int,int> PR;

int ara[MAX], sec[MAX];
int n, m, s, e, dp[MAX][310];
vector<int> mat[MAX];

int ok(int i,int j)
{
    return (j * e + (i + dp[i][j] + 1) <= s) ? 1 : 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int t, prin = 0;

    cin >> n >> m >> s >> e;
    FOR(i,0,n-1) cin >> ara[i];
    FOR(i,0,m-1)
    {
        cin >> sec[i];
        mat[ sec[i] ].PB( i );
    }

    FOR(i,0,n)
    FOR(j,0,300) dp[i][j] = m + 1;

    dp[0][0] = -1; t = s / e; t += 2;
    FOR(i,0,n-1)
    {
        int v = ara[i];
        FOR(j,0,t)
        {
            if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            int p = upper_bound(mat[v].begin(), mat[v].end(), dp[i][j]) - mat[v].begin();

            if(p == sz(v) || sec[ mat[v][p] ] != v) continue;
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], mat[v][p]);

            if(ok(i + 1, j + 1)) prin = max(prin, j + 1);

        }
    }

    cout << prin << endl;

    return 0;
}
