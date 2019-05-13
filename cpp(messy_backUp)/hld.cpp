#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define PB push_back
#define LL long long
#define MAX 30010

vector<int> mat[MAX];
int sz[MAX], paa[MAX], lev[MAX], dfa[MAX], pos[MAX], head[MAX], mxChild[MAX], ti;

void dfs(int p,int pa)
{
    sz[p] = 1; mxChild[p] = -1;
    for(auto x : mat[p])
    {
        if(x == pa) continue;

        paa[x] = p; lev[x] = lev[p] + 1;
        dfs(x, p); sz[p] += sz[x];

        if(sz[ mxChild[p] ] < sz[x]) mxChild[p] = x;

    }
}

void init_hld(int p,int pa,int hd)
{
    head[p] = hd; pos[p] = ++ti; ///dfa[]

    if(mxChild[p] != -1) init_hld(mxChild[p], p, hd);
    for(auto x : mat[p])
    {
        if(x == pa || mxChild[p] == x) continue;
        init_hld(x, p, x);
    }
}

int get_lca(int u,int v)
{
    int r1 = head[u], r2 = head[v];

    if(r1 == r2) return (lev[u] < lev[v]) ? u : v;
    else if(lev[r1] < lev[r2]) return get_lca(u, paa[r2]);
    else return get_lca(paa[r1], v);
}

LL bit[MAX], in[MAX];
void update(int p,int v) ///change value of position p to v
{
	int dv = v - in[p];
	in[p] = v;
	for (; p <= MAX; p += p & (-p)) bit[p] += dv;
}
LL query(int p)
{
	LL rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

LL ran_val(int u,int v)
{
    if(pos[u] > pos[v]) swap(u, v);
    return query(pos[v]) - query(pos[u] - 1);
}

LL get_val(int u,int v)
{
    int r1 = head[u], r2 = head[v];

    if(r1 == r2) return ran_val(u, v);
    else if(lev[r1] < lev[r2]) return get_val(u, paa[r2]) + ran_val(head[v], v);
    else return get_val(paa[r1], v) + ran_val(head[u], u);
}

int ara[MAX];

///for any node always use pos[V] to update or query Vth node
void solve() ///0 bases number please check input j u and v ++ kora hoiche
{
    int n, u, v, ty, q; ti = 0;

    scanf("%d", &n); FOR(i,0,n) mat[i].clear(); /// number of node
    FOR(i,1,n) scanf("%d", &ara[i]); ///value of each node
    FOR(i,1,n-1)
    {
        scanf("%d", &u); scanf("%d", &v);
        u++; v++;
        mat[u].PB( v );
        mat[v].PB( u );
    }
    dfs(1, 1);
    init_hld(1, 1, 1);
    memset(bit, 0, sizeof(bit)); memset(in, 0, sizeof(in));

    FOR(i,1,n) update(pos[i], ara[i]);
    scanf("%d", &q);
    FOR(oo,1,q)
    {
        scanf("%d", &ty); scanf("%d", &u); scanf("%d", &v);
        if(ty == 0) printf("%lld\n", get_val(u + 1, v + 1));
        else update(pos[u + 1], v);
    }


}

int main()
{
    ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);///cin >> tc;
    FOR(tt,1,tc)
    {
        printf("Case %d:\n", tt);
        solve();
    }

    return 0;
}

