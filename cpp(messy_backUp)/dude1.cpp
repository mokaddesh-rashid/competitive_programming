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
#define MAX 305
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> PR;

int dis[90005][600], n, m, id[305][305], val[90005];
vector<int> mat[90005];
int fx[] = {0, 0, -1, 1};
int fy[] = {1, -1, 0, 0};
string str[305];


int giveId(int n,int m)
{
    int p = 0;
    FOR(i,0,n-1)
        FOR(j,0,m-1) id[i][j] = p++;
    return p;
}
int getId(int u,int v) {return id[u][v];}

int giveConnection(int x,int y)
{
    int u = getId(x, y), v;
    FOR(i,0,3)
    {
        int a = x + fx[i], b = y + fy[i];
        if(!valid(a, b)) continue;

        v = getId(a, b);
        mat[u].PB( v );
    }
}

void init(int n,int m)
{
    int p = giveId(n, m);

    FOR(i,0,p) mat[i].clear();

    FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
            giveConnection(i, j);

            int v = getId(i, j);
            val[ v ] = str[i][j] - '0';
        }

    return;
}

int vis[MAX];
queue<int> que;

int bfs(int p)
{
    for(auto x : mat[p]) vis[x] = 0;
    que.PB( p );

    while()

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;i

    cin >> n >> m;
    FOR(i,0,n-1) cin >> str[i];
    init(n, m);

    bfs()

    return 0;
}
