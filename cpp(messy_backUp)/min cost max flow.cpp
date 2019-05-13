#include <stdio.h>
#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))

using namespace std;

/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

const int N = 110, INF = (1e9);

namespace mcmf
{
        int s,t,vis[N],d[N],head[N],cur[N],etot;
        struct edge {int v,cap,cost,next;}g[555555];
        void add_edge(int u,int v,int cap,int cost)
        {
                g[etot] = (edge) {v,cap,cost,head[u]}; head[u] = etot ++;
                g[etot] = (edge) {u,0,-cost,head[v]}; head[v] = etot ++;
        }
        void init()
        {
                memset(head,-1,sizeof(head)); etot = 0;
                memset(d,0,sizeof(d));
        }
        int aug(int u,int a)
        {
                if (u==t) return a;
                vis[u] = 1;
                for (int &i = cur[u]; i != -1; i = g[i].next)
                {
                        edge &e = g[i];
                        if (e.cap && !vis[e.v] && d[u]==d[e.v]+e.cost)
                                if (int tmp = aug(e.v,min(a,e.cap)))
                                {
                                        ///cout << u << ' ';
                                        e.cap -= tmp;
                                        g[i^1].cap += tmp;
                                        return tmp;
                                }
                }
                return 0;
        }
        bool modlabel()
        {
                int tmp = INF;
                for (int u = 0; u < N; u ++) if (vis[u])
                {
                        for (int i = head[u]; i != -1; i = g[i].next)
                        {
                                edge &e = g[i];
                                if (e.cap && !vis[e.v])
                                        tmp = min(tmp,d[e.v]+e.cost-d[u]);
                        }
                }
                if (tmp==INF) return true;
                for (int u = 0; u < N; u ++) if (vis[u])
                {
                        vis[u] = 0;
                        d[u] += tmp;
                }
                return false;
        }
        int min_cost_flow(int _s,int _t)
        {
                s = _s; t = _t;
                int cost = 0,tmp;
                while (true)
                {
                        memcpy(cur,head,sizeof(head));
                        while (tmp=aug(s,INF))
                        {
                                cost += tmp*d[s];
                                memset(vis,0,sizeof(vis));
                        }
                        if (modlabel()) break;
                }
                return cost;
        }
};



int main()
{
    ios::sync_with_stdio(false);
    inf;

    int n, m, u, v, src, des, org;

    scanf("%d", &n);

    src = 0; des = n + 1; org = des + 1;
    mcmf::init();

    for(int u = 1; u <= n; u++)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &v);
            mcmf::add_edge(u, v, 1, -1);
            mcmf::add_edge(u, v, 110, 0);
        }
        mcmf::add_edge(src, u, 1, 0);
        mcmf::add_edge(u, des, 1, 0);
    }

    mcmf::add_edge(org, src, 1, 0);
    cout << mcmf::min_cost_flow(org, des) << endl;
}


