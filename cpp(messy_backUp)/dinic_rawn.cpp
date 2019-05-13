#include<bits/stdc++.h>

using namespace std;

#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1000000000
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           (100010)
#define PI           acos(-1.0)
#define eps          .0000000001

#define cnd          tree[node]
#define lnd          tree[(node * 2)]
#define rnd          tree[((node * 2) + 1)]

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<int> PQ;
typedef queue<int> Q;
typedef stringstream SS;

int node, edge;
int src, des;
vector<int> adjl[110];
vector<int> rc[110];///residual capacity
vector<int> rev_idx[110];///reverse_index

void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(w);
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

void clean()
{
    FOR(i, 1, node)
    {
        adjl[i].clear();
        rc[i].clear();
        rev_idx[i].clear();
    }
}
int lev[110];
int vis[110];
bool dinic_bfs()  { //this finds level of all nodes from source
    MEM(vis, 0);
    MEM(lev, 0);
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

int shuru[110];
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

int dinic()
{
    //cout << "\n\n";
    int ans = 0;
    while(dinic_bfs()) {
        MEM(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, INF);
            //cout << "\n";
            if(ff == 0)break;
            ans += ff;
        }
    }
    //cout << "ans : " << ans
    //cout << "\n\n";
    return ans;
}

int main()  {
    //INP;
    //OUT;
    BOOST;
    //int mx = 0;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)  {
        cin >> node;
        cin >> src >> des >> edge;
        inp();
        //dinic();
        cout << "Case " << tt << ": ";
        cout << dinic() << "\n";
    }
    return 0;
}
/**
2
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20
*/
