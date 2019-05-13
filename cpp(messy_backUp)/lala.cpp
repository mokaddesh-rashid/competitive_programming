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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int sparceT[17][MAX], lev[MAX], n;
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        lev[x] = lev[p] + 1;
        sparceT[0][x] = p;
        dfs(x, p);
    }
    return;
}

void make_sparceT()
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
    while(true)
    {
        int to = sparceT[jump][u];

        if(lev[u] == v) return u;
        else if(to == -1 || lev[to] < v) jump--;
        else u = to;
    }

}


int fin_Lca(int u,int v,int jump)
{
    while(true)
    {
        int t1 = sparceT[jump][u], t2 = sparceT[jump][v];

        if(u == v) return u;
        if(jump == 0 && t1 == t2) return t1;

        else if(t1 == t2) jump--;
        else u = t1, v = t2;
    }
}

int lca(int u,int v)
{
    if(lev[u] < lev[v]) swap(u, v);
    u = make_same(u, lev[v], 16);
    return fin_Lca(u, v, 16);
}

///segment tree part
int tree[4*MAX];

void update(int idx,int b,int e)
{
    if(b == e)
    {
        tree[idx] = b;
        return;
    }

    int m = (b + e)>>1;

    update(lnd, b, m); update(rnd, m + 1, e);
    tree[idx] = lca(tree[lnd], tree[rnd]);
    return;
}

int query(int idx,int b,int e,int st,int en)
{
    if(st > e || en < b ) return -1;
    if(st <= b && en >= e) return tree[idx];

    int m = (b + e)>>1;

    int lf = query(lnd, b, m, st, en);
    int rg = query(rnd, m + 1, e, st, en);

    if(lf == -1) return rg;
    if(rg == -1) return lf;
    return lca(rg, lf);
}

int bao, chi, ja;
int fin(int b,int e)
{
    if(e == b) return b;

    int m = (b + e)>>1;

    int l = query(1, 1, n, b, m);
    int r = query(1, 1, n, m + 1, e);
    cout << b << ' ' << e << ' ' << l << ' ' << r << endl;

    if(l != bao && r != bao)
    {
        if(chi + 1 == ja) return (lev[chi] < lev[ja]) ? chi : ja;
        else if(b == m && e == m + 1)
        {
            while(chi == b || chi == e) {chi++;}
            return (lev[ lca(chi, b) ] < lev[ lca(chi, e) ]) ? b : e;
        }
        else return (b == m) ? b : e;
    }
    else if(lev[l] < lev[r]) return fin(b, m);
    else if(lev[l] == lev[r]) return b;
    else return fin(m + 1, e);
}

int main()
{
    int u, v, q, l, r;
    inf;
//    outf;

    sff(n, q);///cin >> n >> q;
    FOR(i,2,n)
    {
        u = i;
        sf(v);///cin >> v;
        mat[u].PB( v );
        mat[v].PB( u );
    }

    mem(sparceT, -1);
    dfs(1, 1);
    make_sparceT();

    update(1, 1, n);
    FOR(oo,1,q)
    {
        sff(l, r);///cin >> l >> r;

        bao = query(1, 1, n, l, r); chi = l; ja = r;
        int g = fin(l, r), h;
        int x = -1, y = -1;

        if(l <= g - 1) x = query(1, 1, n, l, g - 1);
        if(g + 1 <= r) y = query(1, 1, n, g + 1, r);

        if(x == -1) h = lev[ y ] ;
        else if(y == -1) h = lev[ x ] ;
        else h = lev[ lca(x, y) ] ;

        pf("%d %d\n", g, h);
        ///pf("%d\n", h);
    }

    return 0;
}
