#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define read         freopen("in.txt", "r", stdin)
#define write        freopen("out.txt", "w", stdout)
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
#define MAX 5005
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int INF = (5000*5000) + 10;
const int IT_MAX = (1<<17);
int bit[IT_MAX + 10];

void update(int p, int dv) ///change value of position p to v
{
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
int query(int p)
{
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
int cost[MAX][MAX], n, ara[MAX], k, dp[MAX], bm[MAX];

void compute(int l,int r,int optl,int optr)
{
    if(l > r) return;

    int mid = (l + r)>>1;
    pair<int,int> best = {INF, -1};

    for(int k = optl; k <= min(mid, optr); k++)
        best = min(best, {dp[k-1] + cost[k][mid], k});

    bm[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main()
{
    ios::sync_with_stdio(false);
    //read;

    cin >> n >> k;
    FOR(i,1,n) cin >> ara[i];
    FOR(i,1,n)
    {
        int c = 0, cnt = 0;
        FOR(j,i,n)
        {
            update(ara[j], 1); cnt++;
            c += (cnt - query( ara[j] ));

            cost[i][j] = c;
        }
        FOR(j,i,n) update(ara[j], -1);
    }

    FOR(i,1,n) dp[i] = INF;
    FOR(i,1,k)
    {
        compute(1, n, 1, n);
        FOR(i,0,n) dp[i] = bm[i];
    }
    cout << dp[n] << endl;

    return 0;
}


