#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("cooling.in", "r", stdin)
#define outf        freopen("cooling.out", "w", stdout)
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
#define MAX 20010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int MAXO = 1e9;

int node, edge;
int src, des;
vector<int> adjl[MAX];
vector<int> rc[MAX], all[MAX];
vector<int> rev_idx[MAX];
vector<int> id[MAX];

void add_edge(int u,int v,int w,int i)
{
    ///cout << u << ' ' << v << ' ' << w << endl;
    adjl[u].PB(v); id[u].PB( i );
    adjl[v].PB(u); id[v].PB( -i );
    rc[u].PB(w);  all[u].PB(w);
    rc[v].PB(0);  all[v].PB(w);
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

int lev[MAX];
int vis[MAX];
bool dinic_bfs()  { //this finds level of all nodes from source
    mem(vis, 0);
    mem(lev, 0);
    lev[src] = 0;
    vis[src] = 1;
    queue<int> myq;
    myq.push(src);
    while(!myq.empty()) {
        int u = myq.front();
        myq.pop();
        int sz = adjl[u].size();
        FOR(i, 0, sz - 1)   {
            int v = adjl[u][i];
            if(rc[u][i] == 0)   {
                continue;
            }
            if(vis[v] == 0) {
                vis[v] = 1;
                lev[v] = lev[u] + 1;
                myq.push(v);
            }
        }
    }
    if(vis[des])    {
        return 1;
    }
    return 0;
}

int shuru[MAX];
int dinic_dfs(int u, int flow) {

    if(u == des)    {
        return flow;
    }
    FOR(i, shuru[u], (int)adjl[u].size() - 1)   {
        shuru[u] = i;
        int v = adjl[u][i];
        if((lev[v] == lev[u] + 1) && (rc[u][i]))    {
            int ff = dinic_dfs(v, min(flow, rc[u][i]));
            if(ff) {
                rc[u][i] -= ff;
                rc[v][ rev_idx[u][i] ] += ff;

                return ff;
            }
        }
    }
    shuru[u] = adjl[u].size();
    return 0;
}

int dinic()
{
    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, MAXO);
            //cout << "\n";
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}

int n, m, in[MAX], dekhao[MAX], out[MAX];
struct edge
{
    int u, v, l, r;
}ed[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int u, v, l, r;

    cin >> n >> m;
    FOR(i,1,m)
    {
        cin >> u >> v >> l >> r;

        in[u] += l; in[v] -= l; /// u r demand komse and v r supply l barse
        ed[i] = {u, v, l, r};
    }

    int prin = 0, c;
    src = 0; des = n + 1;
    l = 0; r  = 0;
    FOR(i,1,n)
    {
        int c = in[i];

        if(c < 0) add_edge(src, i, -c, 0);
        else add_edge(i, des, c, 0);

        if(in[i] > 0) prin += c;
    }
    FOR(i,1,m)
    {
        u = ed[i].u; v = ed[i].v; c = ed[i].r - ed[i].l;
        add_edge(u, v, c, i);
        dekhao[i] += ed[i].l;
    }

    if(dinic() == prin)
    {
        cout << "YES" << endl;

        FOR(u,1,n)
        {
            int sz = adjl[u].size();
            FOR(i, 0, sz - 1)   {
                int v = adjl[u][i];
                if(id[u][i] <= 0) continue;
                dekhao[ id[u][i] ] += (all[u][i] - rc[u][i]);
            }
        }

        FOR(i,1,m) cout << dekhao[i] << endl;
    }
    else cout << "NO" << endl;

    return 0;
}


