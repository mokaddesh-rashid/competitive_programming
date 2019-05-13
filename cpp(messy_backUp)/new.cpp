#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out2.txt", "w", stdout)
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

int ara[MAX], n, tar, M, dp[MAX][21], col[MAX][21], cc, shuru[21], sesh[21];

int rec(int p,int r)
{
    if(p > tar) return 0;
    if(p == tar) return (r == 0);

    if(col[p][r] == cc) return dp[p][r];

    col[p][r] = cc;

    int nr = (r + ara[p]);
    if(nr >= M) nr -= M;

    dp[p][r] = rec(p + 1, r) + rec(p + 1, nr);
    if(dp[p][r] >= mod) dp[p][r] -= mod;

    return dp[p][r];
}

int getVal(int l,int r)
{
    int mid = (l + r)>>1;
    //cout << l << ' ' << r << ' ' << mid << endl;

    tar = mid; cc++;
    FOR(i,0,M-1) shuru[i] = rec(l, i);// cout << i << ' ' << rec(l, i) << endl;

    tar = r + 1; cc++;
    FOR(i,0,M-1) sesh[i] = rec(mid, i);// cout << i << ' ' << rec(mid, i) << endl;

    LL s = 0;
    FOR(i,0,M-1)
    {
        if(!i) s += ((LL)shuru[0] * sesh[0]);
        else s += ((LL)shuru[i] * sesh[M - i]);
        s %= mod;
    }
    ///cout << endl << endl;

    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int q, l, r;

    cin >> n >> M;

    FOR(i,0,n-1) cin >> ara[i], ara[i] %= M;

    cin >> q;
    FOR(ll,0,q-1)
    {
        cin >> l >> r;
        cout << getVal(l - 1, r - 1) << endl;
    }

    return 0;
}
