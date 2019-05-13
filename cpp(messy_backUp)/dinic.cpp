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

const int INF = 1000000000;

int node, edge;
int src, des, n, m, c, d;
vector<int> adjl[110];
vector<int> rc[110];///residual capacity
vector<int> rev_idx[110];///reverse_index


void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);
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
int lev[110];
int vis[110];
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

//int shuru[110];
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

void rev_edge(int u,int tar,int ff)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] += ff;
            rc[v][ rev_idx[u][i] ] -= ff;
        }
    }
    return;
}

void off_edge(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] = 0;
            rc[v][ rev_idx[u][i] ] = 0;
        }
    }
    return;
}

void on_edge(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] = 0;
            rc[v][ rev_idx[u][i] ] = 1;
        }
    }
    return;
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

int main()
{
//inf;
//   outf;

    int tc;
    sf(tc);///cin >> tc;
    FOR(tt, 1, tc)
    {
        c = d = 0;
        sff(n, m);///cin >> n >> m;
        src = 0; node = des = n + m + 1;
        inp();

        if(dinic() == c && c == d)
        {
            printf("Case %d:\n", tt);
            FOR(u,1,n)
            {
                FOR(i, 0, (int)adjl[u].size() - 1)
                {
                    int v = adjl[u][i];
                    if(v != src)
                    {
                        if(!rc[u][i] && rc[v][ rev_idx[u][i] ])
                        {
                            rev_edge(src, u, 1);
                            rev_edge(v, des, 1);
                            off_edge(u, v);

                            if(dinic())  printf("0");
                            else  printf("1"),
                                rev_edge(src, u, -1),
                                rev_edge(v, des, -1),
                                on_edge(u, v);
                        }
                        else  printf("0"), off_edge(u, v);
                    }
                }
                 printf("\n");
            }
        }
        else  printf("Case %d: impossible\n", tt);
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
