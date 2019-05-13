#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)

const int MAX = 20;

int dis[MAX][MAX], dp[MAX][1<<MAX], n, m;

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    outf;

    int n, m, u, v;

    cin >> n >> m;
    FOR(i,1,m)
    {
        cin >> u >> v; u--; v--;
        dis[v][u] = dis[u][v] = 1;
    }

    int til = (1<<n) - 1;
    FOR(mask,1,til)
    {
        FOR(i,0,n-1)
        {
            if(mask == (1<<i)) dp[i][mask] = 1;

            if((mask & (1<<i)))
            {
                FOR(j,0,n-1)
                {
                    if((mask & (1<<j)) && dis[i][j])
                       dp[i][mask] +=  dp[j][(mask ^ (1<<i))];
                }
            }
        }
    }

    return 0;
}
