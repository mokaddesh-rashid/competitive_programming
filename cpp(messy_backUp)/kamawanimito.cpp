#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define MAX 400005
#define Val first
#define lazy second
#define F first
#define S second

typedef pair<LL,LL> pii;

const LL INF = (LL)10000000000000000;
pii tree[4*MAX];

void update_node(int idx, int b, int e,LL v)
{
    cnd.Val += v;
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    int m = (b+e)>>1;

    update_node(lnd, b, m, cnd.lazy);
    update_node(rnd, m + 1, e, cnd.lazy);

    cnd.lazy = 0;
}

LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return INF;
    if(st <= b && en >= e) return tree[idx].Val;

    lazy_update(idx, b, e);

    int m = (b+e)>>1;

    return min(query(lnd, b, m, st, en), query(rnd, m + 1, e, st, en));
}

void update(int idx, int b, int e, int st, int en,int v)
{
    if(st > e || en < b ) return;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return;
    }

    lazy_update(idx, b, e);

    int m = (b+e)>>1;
    update(lnd, b, m, st, en, v); update(rnd, m + 1, e, st, en, v);
    cnd.Val = min(tree[lnd].Val, tree[rnd].Val);
}

LL dp[MAX], prin, lolo;
vector<pii> mat[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    int n, m, l, r, c;

    cin >> n >> m;
    FOR(i,0,m-1)
    {
        cin >> l >> r >> c; prin += c;
        mat[r].push_back( {l, c} );
    }

    int base = 1;
    while(base <= n) {base *= 2;}

    FOR(i,1,n + 1)
    {
        dp[i] = query(1, 0, base, 0, i - 1);

        for(auto x : mat[i])
             update(1, 0, base, 0, x.F - 1, x.S);

        update(1, 0, base, i, i, dp[i]);
    }

    cout << prin - dp[n + 1] << endl;

    return 0;
}
