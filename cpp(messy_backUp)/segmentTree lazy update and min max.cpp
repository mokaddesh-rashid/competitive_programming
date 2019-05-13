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
#define MAX 200005
#define Val first
#define lazy second
#define F first
#define S second

typedef pair<LL,LL> pii;

const LL INF = (LL)100000000000000000;
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


void update(int idx, int b, int e, int st, int en,LL &v,int type)
{
    if(st > e || en < b ) return;
    if(st <= b && en >= e && !type)
    {
        update_node(idx, b, e, v);
        return;
    }
    if(st <= b && en >= e)
    {
        v = min(v, tree[idx].Val);
        return;
    }

    lazy_update(idx, b, e);

    int m = (b+e)>>1;

    update(lnd, b, m, st, en, v, type);
    update(rnd, m + 1, e, st, en, v, type);

    cnd.Val = min(tree[lnd].Val, tree[rnd].Val);
}

LL dp[MAX], prin, lolo;
vector<pii> mat[MAX];

int main()
{
    ios::sync_with_stdio(false);
   // inf;

    int n, m, l, r, c;
    lolo = INF;

    cin >> n >> m;
    FOR(i,0,m-1)
    {
        cin >> l >> r >> c; prin += c;
        mat[r].push_back( {l, c} );
    }

    int base = n;

    FOR(i,1,n + 1)
    {
        dp[i] = INF;
        update(1, 0, base, 0, i - 1, dp[i], 1);

        for(auto x : mat[i])
             update(1, 0, base, 0, x.F - 1, x.S, 0);

        update(1, 0, base, i, i, dp[i], 0);
    }

    cout << prin - dp[n + 1] << endl;

    return 0;
}
