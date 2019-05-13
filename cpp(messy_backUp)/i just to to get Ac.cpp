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
#define MAX (40*40*5 + 100)
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int mat[41][41], cnt[MAX];

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
    FOR(i, 0, MAX - 1)
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


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    for(;;)
    {
        int n, m, g, u, v; mem(mat, 0); mem(cnt, 0);
        char ch;

        cin >> n >> m >> g;
        if(!n && !m && !g) break;

        FOR(i,0,g-1)
        {
            cin >> u >> ch >> v;
            if(ch == '=') cnt[u]++, cnt[v]++;
            else if(ch == '>') cnt[u] += 2;
            else cnt[v] += 2;

            mat[u][v]++; mat[v][u]++;
        }

        int sum = 0, id = n, moa = 0;

        src = id++; node = des = id++;
        init_flow();

        FOR(i,1,n-1)
        {
            cnt[0] += (m - mat[0][i]) * 2;
            mat[0][i] = m; moa = max(moa, cnt[i]);
        }
        FOR(i,1,n-1)
        {
            FOR(j,i+1,n-1)
            {
                FOR(k,mat[i][j],m-1)
                {
                    add_edge(src, id, 2); sum += 2;
                    add_edge(id, i, 2);
                    add_edge(id, j, 2);
                    id++;
                }
                mat[i][j] = m;
            }
        }
        ///cout << sum << ' ' << cnt[0] << endl;
        FOR(i,1,n-1) add_edge(i, des, max(0, cnt[0] - cnt[i] - 1));

        if(dinic() == sum && cnt[0] > moa) cout << 'Y' << endl;
        else cout << 'N' << endl;
    }

    return 0;
}

