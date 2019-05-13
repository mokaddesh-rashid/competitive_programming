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
#define MAX 10010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

#define MAXNODE 1005
#define MAXEDGE 10005
const int INF = 1e9;
struct Edge
{
    int u, v;
    int dis;
    Edge() {}
    Edge(int _u, int _v, int _dis) { u = _u; v = _v; dis = _dis; }
};
int n, m;
Edge edges[MAXEDGE],keep[MAXEDGE];
int bw[MAXEDGE];
int vis[MAXNODE];
int pre[MAXNODE];
int id[MAXNODE];
int in[MAXNODE];

void init(int _n) { n = _n; m = 0; }
void AddEdge(int u, int v, int dis) { edges[m++] = Edge(u, v, dis); }

///0 based indexing
int directedMST(int root)
{
    int ans = 0;
    while(1)
    {
        for (int i = 0; i < n; i++) in[i] = INF;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            /// find the smallest edge, delete the ring
            if(edges[i].dis < in[v] && u != v)
            {
                in[v] = edges[i].dis;
                pre[v] = u;
            }
        }

        /// If there is no minimum entry, it means that the point is not connected, the smallest tree does not fail
        for (int i = 0; i < n; i++)
        {
            if (i == root) continue;
            if (in[i] == INF) return -1;
        }

        int cnt = 0;/// record shrink points
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;/// tree root can not have edge
        for (int i = 0; i < n; i++)
        {
            ans += in[i];
            int v = i;
            /// find the ring
            while (vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            /// find the ring
            if (v != root && id[v] == -1)
            {
                for (int u = pre[v]; u != v; u = pre[u]) id[u] = cnt;
                id[v] = cnt++;
            }
        }

        /// If there is no self-loop, said the smallest tree shape to succeed
        if (cnt == 0) break;

        /// find those that are not self-looped and re-mark those points
        for (int i = 0; i < n; i++) if (id[i] == -1) id[i] = cnt++;

        for (int i = 0; i < m; i++)
        {
            int v = edges[i].v;
            edges[i].v = id[edges[i].v];
            edges[i].u = id[edges[i].u];
            if (edges[i].u != edges[i].v) edges[i].dis -= in[v];
        }
        /// After the end of the point, the number of points on the side
        n = cnt;
        root = id[root];
    }
    return ans;
}

int main()
{
    ///ios::sync_with_stdio(false);
   /// inf;
    //outf;

    int tc;

    sf(tc);///cin >> tc;

    FOR(tt,1,tc)
    {
        int K, x, y, w, cc;
        sfff(n, cc, K);////cin >> n >> m >> K;
        init( n );

        FOR(i,0,cc-1)
        {
            sfff(x, y, w);
            AddEdge(x, y, w);
        }
        int val = directedMST( K );

        if(val == -1) printf("Case %d: impossible\n", tt);
        else printf("Case %d: %d\n", tt, val);
    }


    return 0;
}

