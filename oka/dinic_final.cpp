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
#define MAX 2010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int MAXO = 1e9;

int node, edge;
int src, des;
vector<int> adjl[MAX];
vector<int> rc[MAX];
vector<int> rev_idx[MAX];

void add_edge(int u,int v,int w)
{
    ///cout << "add " << u << ' ' << v << ' ' << w << endl;
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

void init_flow()
{
    FOR(i, 0, node)
    {
        adjl[i].clear();
        rc[i].clear();
        rev_idx[i].clear();
    }
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

pair<int, PR> ed[MAX*20];
int p, r, c, need, dude, in[MAX], out[MAX];

int main()
{
    ios::sync_with_stdio(false);
   // inf;
    //outf;
    int a;

    cin >> p >> r >> c;
    src = 0; des = p + r + 1; node = des;

    FOR(i,1,p)
    {
        cin >> a; in[i] = a;
        need += a;
    }
    FOR(i,1,r)
    {
        cin >> a; out[i] = a;
    }

    FOR(i,0,c-1)
        cin >> ed[i].S.F >> ed[i].S.S >> ed[i].F;

    sort(ed, ed + c);

    int show = -1, st = 0, en = c - 1, mid;

    while(st <= en)
    {
        mid = (st + en)>>1;

        init_flow();
        FOR(i,0,mid)
            add_edge(p + ed[i].S.S, ed[i].S.F, MAXO);
        FOR(i,1,p)
            add_edge(i, des, in[i]);
        FOR(i,1,r)
            add_edge(src, p + i, out[i]);

        if(dinic() == need)
        {
            en = mid - 1;
            show = show == -1 ? ed[mid].F : min(show, ed[mid].F);
        }
        else st = mid + 1;

    }

    cout << show << endl;

    return 0;
}


