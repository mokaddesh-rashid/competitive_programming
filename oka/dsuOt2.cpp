#include<bits/stdc++.h>

using namespace std;

#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define MAX 500010
#define FOR(i,j,k) for(int i=j; i<=k; i++)


bool tree[4*MAX];
int lf[MAX], rg[MAX], ti, par[MAX];
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    lf[p] = ++ti;
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        dfs(x, p);
        par[x] = p;
    }
    rg[p] = ti;
}

void update(int idx,int b,int e,int l,int r,int v)
{
    if(b > r || e < l) return;
    if(l <= b && e <= r)
    {
        tree[idx] = v;
        return;
    }
    if(tree[idx]) tree[ lnd ] = tree[ rnd ] = 1;

    int mid = (b + e)>>1;

    update( lnd, b, mid, l, r, v);
    update( rnd, mid + 1, e, l, r, v);

    tree[idx] = tree[ lnd ] & tree[rnd];
}

int query(int idx,int b,int e,int l,int r)
{
    if(b > r || e < l) return 1;
    if(l <= b && e <= r) return tree[idx];
    if(tree[idx]) tree[ lnd ] = tree[ rnd ] = 1;

    int mid = (b + e)>>1;

    int ql = query(lnd, b, mid, l, r);
    int qr = query(rnd, mid + 1, e, l, r);

    return ql & qr;
}

int main()
{
    ios::sync_with_stdio( false );
    ///freopen("in.txt", "r", stdin);

    int n, u, v, q;

    scanf("%d", &n);///cin >> n;
    FOR(i,1,n-1)
    {
        scanf("%d %d", &u, &v);//cin >> u >> v;
        mat[u].push_back( v );
        mat[v].push_back( u );
    }
    dfs(1, 1);

    scanf("%d", &q);
    FOR(i,1,q)
    {
        scanf("%d %d",&u, &v);

        if(u == 1)
        {
            int c = query(1, 1, MAX - 1, lf[v], rg[v]);
            update(1, 1, MAX - 1, lf[v], rg[v], 1);
            if(par[v] && !c)
                update(1, 1, MAX - 1, lf[ par[v] ], lf[ par[v] ], 0);

        }
        else if(u == 2) update(1, 1, MAX - 1, lf[v], lf[v], 0);
        else printf("%d\n", query(1, 1, MAX - 1, lf[v], rg[v]));

    }

    return 0;
}
