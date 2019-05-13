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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int INF = 100000;

int node, edge;
int src, des, n, m, c, d;
vector<int> adjl[210], typ[210];
vector<int> rc[210];///residual capacity
vector<int> rev_idx[210];///reverse_index


void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);

    typ[u].PB(1);
    typ[v].PB(0);

    rc[u].PB(w);
    rc[v].PB(0);///one directional

    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}
void inp()
{
    FOR(i, 0, node)
    {
        adjl[i].clear();
        rc[i].clear();
        rev_idx[i].clear();
    }
    int a;
    FOR(i, 1, n + m)
    {
        cin >> a;
        if(i <= n) add_edge(src, i, a), c += a;
        else add_edge(i, des, a), d += a;

    }

    FOR(i,1,n)
    FOR(j,1,m) add_edge(i, j + n, 1);
}
int lev[210];
int vis[210];
bool dinic_bfs()
{ //this finds level of all nodes from source
    mem(vis, 0);
    mem(lev, 0);
    lev[src] = 0;
    vis[src] = 1;
    queue<int> myq;
    myq.push(src);
    while(!myq.empty())
    {
        int u = myq.front();
        myq.pop();
        int sz = adjl[u].size();
        FOR(i, 0, sz - 1)
        {
            int v = adjl[u][i];
            if(rc[u][i] == 0)
            {
                continue;
            }
            if(vis[v] == 0)
            {
                vis[v] = 1;
                lev[v] = lev[u] + 1;
                myq.push(v);
            }
        }
    }
    if(vis[des])
    {
        return 1;
    }
    return 0;
}

//int shuru[210];
int dinic_dfs(int u, int flow)
{
    //cout << u << " " << flow << "\n";
    if(u == des)
    {
        return flow;
    }
    int ans = 0;
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        if(flow == 0)
        {
            break;
        }
        int v = adjl[u][i];
        if(lev[v] == lev[u] + 1)
        {
            int ff = dinic_dfs(v, min(flow, rc[u][i]));
            rc[u][i] -= ff;
            rc[v][ rev_idx[u][i] ] += ff;
            flow -= ff;
            ans += ff;
        }
    }
    return ans;
}

int dinic()
{
    //cout << "\n\n";
    int ans = 0;
    while(dinic_bfs())
    {
        ans += dinic_dfs(src, INF);
    }
    //cout << "ans : " << ans
    //cout << "\n\n";
    return ans;
}

int edgeVal(int u,int tar)
{
    int ret;
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar) ret += rc[v][ rev_idx[u][i] ];
    }
    return ret;
}

int prin[210][210], in[210], out[210];

int main()
{
    ios::sync_with_stdio(false);
   /// inf;

    int c = 0, m, k, a, b, l, r;

    cin >> n >> m;

    src = 0;
    FOR(i,1,n) in[i] = ++c;
    FOR(i,1,n) out[i] = ++c;
    des = ++c;

    FOR(i,1,n)
    {
        ///cout << i << ' ' << in[i] << ' ' << out[i] << ' ' << INF << endl;
        add_edge(in[i], out[i], INF);
    }

    l = r = 0;
    FOR(i,1,n + n)
    {
        cin >> a;
        if(i <= n) add_edge(0, in[i], a), l += a;///cout << 0 << ' ' << in[i] << ' ' << a << endl;
        else add_edge(out[i - n], des, a), r += a;///cout << out[i - n] << ' ' << t << ' ' << a << endl;
    }

    FOR(i,1,m)
    {
        cin >> a >> b;
        add_edge(in[a], out[b], INF);
        add_edge(in[b], out[a], INF);
    }

    ///cout << l << ' ' << r << ' ' << dinic() << endl;
    if(dinic() == l && r == l)
    {
        FOR(p,1,n)
        {
            int u = in[p];
            FOR(i, 0, (int)adjl[u].size() - 1)
            {
                int v = adjl[u][i];
                prin[u][v - n] = rc[v][ rev_idx[u][i] ];
               /// if(typ[u][i]) cout << p << ' ' << v << ' ' << rc[u][i] << ' ' << rc[v][ rev_idx[u][i] ] << endl;
            }
        }

        cout << "YES" << endl;
        FOR(i,1,n)
        {
            FOR(j,1,n) cout << prin[i][j] << ' ';
            cout << endl;
        }
    }
    else cout << "NO" << endl;


    return 0;
}
