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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int sparceT[17][MAX], lev[MAX], st[MAX], en[MAX], ti;
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    st[p] = ++ti;
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        lev[x] = lev[p] + 1; sparceT[0][x] = p;
        dfs(x, p);
    }
    en[p] = ++ti;
    return;
}

void make_sparceT(int n)
{
    FOR(i,1,16)
        FOR(j,1,n)
        {
            int x = sparceT[i - 1][j];
            if(x == -1) continue;
            sparceT[i][j] = sparceT[i - 1][x];
        }
}

int make_same(int u,int v,int jump)
{
    int to = sparceT[jump][u];

    if(lev[u] == lev[v]) return u;
    else if(to == -1 || lev[to] < lev[v]) return make_same(u, v, jump - 1);
    else return make_same(to, v, jump);

}

int fin_Lca(int u,int v,int jump)
{
    int t1 = sparceT[jump][u], t2 = sparceT[jump][v];

    if(u == v) return u;
    if(jump == 0 && t1 == t2) return t1;
    else if(t1 == t2) return fin_Lca(u, v, jump - 1);
    else return fin_Lca(t1, t2, jump);
}

int lca(int u,int v)
{
    if(lev[u] < lev[v]) swap(u, v);
    u = make_same(u, v, 16);
    return fin_Lca(u, v, 16);
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    int n, u, v, q;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB( v );
        mat[v].PB( u );
    }

    mem(sparceT, -1);
    dfs(1, 1);
    make_sparceT( n );
    return 0;
}
