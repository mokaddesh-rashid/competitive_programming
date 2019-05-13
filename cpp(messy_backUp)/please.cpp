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
#define MAX 5010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

struct edge
{
    int a, b, cost;
};

int n, m;
vector<edge> e;
const int INF = 1000000000;
int vis[MAX];
vector<int> mat[MAX];

void dfs(int p)
{
    vis[p] = 1;

    for(auto x: mat[p])
    {
        if(vis[x]) continue;
        dfs(x);
    }
}

int solve(int v)
{
    int p = 0;
    vector<int> d (n, INF);

    d[v] = 0;
    for (;;)
    {
        p++;
        bool any = false;

        for (int j=0; j<m; ++j)
            if(vis[ e[j].a] && vis[ e[j].b ] && d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                }

        if (!any || p == n + 1) break;
    }

    if(d[v] < 0 || p == n + 1) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        edge ed;

        cin >> n >> m;
        e.clear(); mem(vis, 0);
        FOR(i,0,n) mat[i].clear();

        FOR(i,0,m-1)
        {
            cin >> ed.a >> ed.b >> ed.cost;
            e.push_back( ed );
            mat[ed.b].PB( ed.a );
        }
        dfs( 0 );
        if(solve( 0 )) cout << "Case #" << tt << ": possible\n";
        else cout << "Case #" << tt << ": not possible\n";

    }

    return 0;
}
