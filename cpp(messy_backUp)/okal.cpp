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
#define MAX 2010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int INF = 1000000000;

int src, des, node;
vector<int> adjl[2010];
vector<int> rc[2010];///residual capacity
vector<int> rev_idx[2010];///reverse_index


void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);///one directional
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

int lev[2010];
int vis[2010];
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

int shuru[2010];
int dinic_dfs(int u, int flow) {
    //cout << u << " " << flow << "\n";
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

int dinic() {

    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, INF);
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}

string str[MAX];
int id[110][110], row[110], col[110];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        int c = 1, prin = 0, n, m;

        src = 0; des = 1;

        cin >> n >> m;
        FOR(i,0,n-1) cin >> str[i];

        FOR(i,0,n-1)
            FOR(ok,0,m-1)
                id[i][ok] = ++c;

        FOR(i,0,n-1) row[i] = ++c;
        FOR(i,0,m-1) col[i] = ++c;
        node = ++c;

        FOR(i, 0, node)
        {
            adjl[i].clear();
            rc[i].clear();
            rev_idx[i].clear();
        }

        FOR(i,0,n-1)
        {
            FOR(ok,0,m-1)
            {
                if(str[i][ok] == '1')
                {
                    prin++;

                    add_edge(src, id[i][ok], 1);
                    add_edge(id[i][ok], row[i], 1);
                    add_edge(id[i][ok], col[ok], 1);

                }
            }
        }

        FOR(i,0,n-1)
            add_edge(row[i], des, 1);

        FOR(i,0,m-1)
            add_edge(col[i], des, 1);

         cout << "Case #" << tt << ": " << n + m - dinic()/2 << endl;
    }


    return 0;
}

