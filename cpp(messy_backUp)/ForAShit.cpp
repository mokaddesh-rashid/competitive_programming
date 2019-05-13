#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define MAX 500010

vector<int> mat[MAX];
int vis[MAX], pa[MAX];

void clean(int n)
{
    FOR(i,0,n+1)
    {
        vis[i] = 0;
        mat[i].clear();
    }
    vis[0] = 1;
}

void dfs(int p,int Bap)
{
    for(auto x : mat[p])
    {
        if(x == Bap) continue;
        pa[x] = p; dfs(x, p);
    }
}

int rec(int p)
{
    if(vis[p]) return 0;
    vis[p] = 1; return 1 + rec( pa[p] );
}

void solve()
{
    int n, u, v, q;

    sf(n); clean( n );
    FOR(i,1,n-1)
    {
        sff(u, v);
        mat[u].PB( v ); mat[v].PB( u );
    }
    dfs(1, 1);///Root is always 1

    sf(q);
    FOR(oo,1,q)
    {
        sf( v );
        printf("%d\n", rec( v ));
    }
    return;
}

int main()
{
//   freopen("in10.txt", "r", stdin);
//   freopen("out10.txt", "w", stdout);
   solve();
   return 0;
}
