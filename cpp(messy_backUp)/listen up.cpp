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
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


vector<int> mat[MAX];
int lev[MAX], n, bap[MAX], val[MAX], pa[MAX];

struct edge
{
   int u, v, w;
};
edge ami[MAX], tmi[MAX];
int k, m;

///dsu
void initDsu()
{
    FOR(i,1,n) pa[i] = i;
}
int finPa(int p)
{
    return (pa[p] == p) ? p : (pa[p] = finPa( pa[p] ));
}
int mergeNode(int u,int v)
{
    int r1 = finPa( u ), r2 = finPa( v );
    if(r1 == r2) return 0;

    pa[r1] = r2;
    return 1;
}

///dfs
void dfs(int p,int pa)
{
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        bap[x] = p;
        lev[x] = lev[p] + 1;
        dfs(x, p);
    }
    return;
}


///**********hand written
class cmp
{
public:
    bool operator()(edge x,edge y)
    {
        return x.w < y.w;
    }
};


void updateNode(int u,int v,int V)
{
    if(u == v) return;
    if(lev[u] < lev[v]) swap(u, v);

    val[u] = min(val[u], V);
    mergeNode(u, bap[u]);

    updateNode(finPa( u ), v, V);
    return;
}

int main()
{
    ///inf;
    //outf;

    sfff(n, k, m);
    FOR(i,0,k-1) sff(ami[i].u, ami[i].v), ami[i].w = 0;
    FOR(i,0,m-1) sfff(tmi[i].u, tmi[i].v, tmi[i].w);

    sort(tmi, tmi + m, cmp());

    initDsu();

    FOR(i,0,k + m - 1)
    {
        edge p;

        if(i < k) p = ami[i];
        else p = tmi[i - k];

        if(mergeNode(p.u, p.v))
        {
            mat[p.u].PB( p.v );
            mat[p.v].PB( p.u );
        }
    }

    dfs(1, 1);

    initDsu();
    FOR(i,1,n) val[i] = 1e9 + 1;
    FOR(i,0,m-1)
    {
        edge p = tmi[i];
        updateNode(p.u, p.v, p.w);
    }

    LL prin = 0;

    FOR(i,0,k-1)
    {
        edge p = ami[i];

        if(bap[p.v] == p.u) swap(p.u, p.v);
        if(val[p.u] == (1e9 + 1))
        {
            printf("-1");
            return 0;
        }
        prin = (LL)prin + val[p.u];
    }

    printf("%I64d", prin);


    return 0;
}

/*

9
1 2
2 4
1 3
3 5
3 6
6 9
1 7
7 8

*/
