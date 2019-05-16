#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> pii;
const int MAX = (5e4) + 5;

int n, m, low[MAX], dis[MAX], ti, can_t[MAX];
vector<pii> mat[MAX], edgeList;

int arti(int p,int pa)
{
    dis[p] = low[p] = ti++;
    for(pii x : mat[p])
    {
        if(x.F == pa) continue;
        else if(dis[x.F] != -1) low[p] = min(low[p], dis[x.F]);
        else
        {
            low[p] = min(low[p], arti(x.F, p));
            if(dis[p] < low[x.F])
            {
                edgeList.PB( {p, x.F} );
                can_t[x.S] = 1;
            }
        }
    }
    return low[p];
}

int id[MAX], vis[MAX], cnt[MAX];
int dfs(int p,int col)
{
    vis[p] = 1; id[p] = col;
    for(pii x : mat[p])
    {
        if(vis[x.F] || can_t[x.S]) continue;
        dfs(x.F, col);
    }
}

int main()
{
    inf;
    outf;
    int tc;

    edgeList.clear(); mem(can_t, 0); mem(low, -1); mem(dis, -1);
    int u, v;

    sff(n, m);
    FOR(i,1,n) mat[i].clear();
    FOR(i,1,m)
    {
        sff(u, v); u++; v++;

        mat[u].PB( {v, i} );
        mat[v].PB( {u, i} );

    }
    arti(1, 1);

    mem(vis, 0); mem(cnt, 0);
    int c = 1;

    FOR(i,1,n) if(!vis[i]) dfs(i, c++);
    for(pii x : edgeList)
    {
        int u = id[x.F], v = id[x.S];
        cnt[u]++; cnt[v]++;
    }

    return 0;
}



