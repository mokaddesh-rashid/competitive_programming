#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define MOD          1000000007
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
typedef pair<LL,LL> pii;

string str;
LL dp[(1<<18) + 5], mul[100005], opp[18][(1<<18) + 5][2];
int n, m;
const int M = (1e9) + 7;

LL rec(int p,int mask,int nb)
{
    if(p == m)
    {
        int x = __builtin_popcount( mask ) % 2;

        if(x == nb) return (mul[ dp[mask] ] - 1);
        else return -(mul[ dp[mask] ] - 1);
    }

    LL &t = opp[p][mask][nb];
    if(t != -1) return t;

    t = M + M + rec(p + 1, mask, nb);

    int newMask = (mask ^ (1<<p));
    if(mask & (1<<p)) t += rec(p + 1, newMask, nb);

    return (t % M);
}

int main()
{
    ios::sync_with_stdio(false);
    mul[0] = 1;
    FOR(i,1,100000) mul[i] = (mul[i - 1] + mul[i - 1]) % M;

    int req = 0, k, v;

    cin >> n;
    FOR(oo,0,n-1)
    {
        cin >> k; dp[k]++;
        req |= k;
    }

    m = 17;
    for(int bit = 0; bit < m; bit++)
        for(int mask = 0; mask <= req; mask++)
            if(mask & (1<<bit)) dp[mask] += dp[(mask ^ (1<<bit))];


    mem(opp, -1);
    FOR(i,0,req) ///i mask hobe or korle amn koro golo sub sequence ache
    {
        int r = __builtin_popcount( i ) % 2;
        cout << rec(0, i, r) << endl;
    }
    return 0;
}

