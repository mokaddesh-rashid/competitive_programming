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
#define maxx          (long long) 1000000000000000
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
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

vector<PR> mat[MAX];
LL dis[MAX];
PR useLife[MAX];
int n, m;

void dfs(int p,int pa,int root)
{
    if(p == pa) dis[p] = 0;

    for(auto x : mat[p])
    {
        if(x.F == pa) continue;
        dis[x.F] = dis[p] + x.S;
        dfs(x.F, p, root);
    }

    if(root == 1) useLife[p].F = dis[p];
    else  useLife[p].S = dis[p];
}

int ase[MAX];

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    cin >> n >> m;

    FOR(i,1,n-1)
    {
        cin >> a >> b >> c;
        mat[a].PB( MP(b, c) );
        mat[b].PB( MP(a, c) );
    }

    dfs(1, 1, 1);
    dfs(n, n, n);

    sort(useLife + 1, useLife + n + 1);




    return 0;
}
