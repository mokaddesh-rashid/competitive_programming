#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> pii;
typedef long long LL;

const int MAX = 200010;
vector<pii> ed[MAX];
int pa[MAX], sz[MAX];

void init()
{
    FOR(i,0,MAX-1) sz[i] = 1, pa[i] = i;
}
int finPa(int p)
{
    return pa[p] == p ? p : pa[p] = fin( pa[p] );
}
void mergeNode(int u,int v)
{
    int r1 = finPa( u ), r2 = finPa( v );
    if(r1 == r2) return;

    sz[r1] += sz[r2];
    pa[r2] = r1;
}

void getSize(int p)
{
    int r1 = finPa( p );
    return sz[r1];
}

LL prin = 0;
int vis[MAX];
stack<int> stk;

void fillStk(int p,int pa)
{
    for(auto x : ed[p])
    {
        if(x.F == pa) continue;
        fillStk(x.F, p);
    }
    stk.push( p );
}

int dfs(int p,int pa,int can)
{
    int ret = 0;
    for(auto x : ed[p])
    {
        if(can && !x.S) continue;
        if(pa == x.F) continue;

        int x = dfs(x, p, (max(can, x.S)));
        prin += (LL)ret * x; ret += x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n;

    init();
    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> u >> v >> t;
        if(!t) mergeNode(u, v);
        ed[u].PB( {v, t} ); ed[v].PB( {u, t} );
    }
    return 0;
}

