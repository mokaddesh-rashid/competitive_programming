#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("network.in", "r", stdin)
#define outf        freopen("network.out", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
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
#define MAX 110
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int MAXN = 201;
const int INF = 1000000000;


struct edge {
    int a, b, cap, flow, idx;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN], m, row, col, node;
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap,int idx) {
    edge e1 = { a, b, cap, 0, idx};
    edge e2 = { b, a, 0, 0, 0};
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

void init_flow()
{
    FOR(i,0,MAX - 1) g[i].clear();
    e.clear();
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, sizeof(d));
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

pair<int, PR> ed[MAX*20];
int n, m;
vector<int> prin;

int doFLow(int mid)
{
    prin.clear();
    init_flow(); s = 1; t = n;
    int need = 0;

    FOR(i,0,m-1)
    {
        int u = ed[i].S.F, v = ed[i].S.S, cost = ed[i].F;
        if(cost >= mid)
        {
            if(u != des && v != 1) add_edge(u, v, cost - mid, i + 1);
            if(v != des && u != 1)add_edge(v, u, cost - mid, i + 1);
        }
        else need += (mid - ed[i].F), prin.PB(i + 1);
    }

    return (dinic() <= need);
}

void in(int u)
{
    int sz = adjl[u].size();
    FOR(i, 0, sz - 1)
        if(rc[u][i] == 0 && typ[u][i]) prin.PB( typ[u][i] );
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    cin >> n >> m;

    FOR(i,0,m-1)
        cin >> ed[i].S.F >> ed[i].S.S >> ed[i].F;

    int show = (1e7), st = 1, en = (1e7), mid, need;

    while(st <= en)
    {
        mid = (st + en)>>1;

        int x = doFLow( mid );
        if(x)
        {
            en = mid - 1;
            show = min(show, mid);
        }
        else st = mid + 1;

    }

    doFLow( show );
    FOR(i,1,n) in( i );

    cout << prin.size() << endl;
    for(auto x : prin) cout << x << ' ';

    return 0;
}
