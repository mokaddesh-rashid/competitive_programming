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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int ara[MAX], n, tar, M, dp[MAX][21], col[MAX][21], mon[MAX][21], rong[MAX][21], cc, shuru[21], sesh[21];

int rec(int p,int r)
{
    if(p > tar) return 0;
    if(p == tar) return (r == 0);

    if(col[p][r] == cc) return dp[p][r];
    col[p][r] = cc;

    int nr = (r + ara[p]); nr %= M;
    return dp[p][r] = ( rec(p + 1, r) + rec(p + 1, nr) ) % mod;
}

int ulta(int p,int r)
{
    if(p == tar - 1) return (r == 0);

    if(rong[p][r] == cc) return mon[p][r];
    rong[p][r] = cc;

    int nr = (r + ara[p]); nr %= M;
    return mon[p][r] = (ulta(p - 1, r) + ulta(p - 1, nr)) % mod;
}


vector< pair<PR,int> > tree[4*MAX];
PR ran[4*MAX];
int show[MAX];

void div(int idx,int b,int e,int st,int en,int p)
{
    int mid = (b + e)>>1; ran[idx] = MP(b, e);

    if(b == e)
    {
        show[p] = (ara[b] == 0) + 1;
    }
    else if(b <= st && en <= mid) div(lnd, b, mid, st, en, p);
    else if(mid + 1 <= st && en <= e) div(rnd, mid + 1, e, st, en, p);
    else
    {
        tree[idx].PB( MP(MP(st, en), p) );
    }
}

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    outf;
    int q, l, r;

    cin >> n >> M;

    FOR(i,0,n-1) cin >> ara[i], ara[i] %= M;

    cin >> q;
    FOR(oo,0,q-1)
    {
        cin >> l >> r;
        div(1, 0, n-1, l - 1, r - 1, oo);
    }

    FOR(p,1,4*MAX - 1)
    {
        if(tree[p].size())
        {
            int l = ran[p].F, r = ran[p].S;
            tar = (l + r)>>1; cc++;

            for(auto v : tree[p])
            {
                FOR(i,0,M-1) shuru[i] = rec(v.F.F, i);
                FOR(i,0,M-1) sesh[i] = ulta(v.F.S, i);

                LL s = 0;
                FOR(i,0,M-1)
                {
                    if(!i) s += ((LL)shuru[0] * sesh[0]);
                    else s += ((LL)shuru[i] * sesh[M - i]);
                    s %= mod;
                }
                show[v.S] = s;
            }
        }
    }

    FOR(i,0,q-1) cout << show[i] << endl;
    return 0;
}
