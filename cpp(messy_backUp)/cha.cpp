
#include <stdio.h>
#include <bits/stdtr1c++.h>

#define MAX 200010 /// 2 * max(nodes, edges)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

/// Min-cost Max-flow using bellman ford
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)
/// Runs in around 0.75 seconds when n <= 100 and m = n * (n - 1) / 2
/// Runs well for sparse graphs though, e.g, m <= 10 * n
/// Costs must be non-negative

const int N = 110, INF = (1e8);

namespace mcmf
{
        int s,t,vis[N],d[N],head[N],cur[N],etot;
        struct edge {int v,cap,cost,next;}g[555555];
        void addEdge(int u,int v,int cap,int cost)
        {
                g[etot] = (edge) {v,cap,cost,head[u]}; head[u] = etot ++;
                g[etot] = (edge) {u,0,-cost,head[v]}; head[v] = etot ++;
        }
        void init()
        {
                memset(head,-1,sizeof(head)); etot = 0;
                for(int i = 0; i < N; i++) d[i] = 0;
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
        int solve(int _s,int _t)
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

#define FOR(i,j,k) for(int i=j;i<=k;i++)
string str;
int n, ara[MAX], cnt[50];

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int n;

    cin >> n;
    cin >> str;
    FOR(i,0,n-1) cin >> ara[i];

    FOR(i,0,n-1) cnt[((int)str[i] - 'a')]++;
    int s = 26 + n/2 + 1;
    int d = s + 1;

    mcmf::init();

    FOR(i,0,25) mcmf::addEdge(s, i, cnt[i], 0);
    for(int i = 0, j = n - 1; i < j; i++, j--) mcmf::addEdge(i + 26, d, 2, 0);

    for(int c = 0; c < 26; c++)
    for(int i = 0, j = n - 1; i < j; i++, j--)
    {
        char mc = (char)c + 'a';

        if(mc == str[i] && mc == str[j]) mcmf::addEdge(c, i + 26, 1, -max(ara[i], ara[j]));
        else if(mc == str[i]) mcmf::addEdge(c, i + 26, 1, -ara[i]);
        else if(mc == str[j]) mcmf::addEdge(c, i + 26, 1, -ara[j]);
        else mcmf::addEdge(c, i + 26, 1, -0);
    }

    cout << -mcmf::solve(s, d) << endl;
    return 0;

}
