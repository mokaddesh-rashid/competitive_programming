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


double rec(double p,int k)
{
    ///cout << p << endl;
    if(k == 0) return p * 2;
    return ((rec(p * 2, k - 1) + rec((p * 2) - 1, k - 1)) * .5);
}

double roro(double p,int k)
{
    ///cout << p << endl;
    if(k == 0) return p * 2;
    return 2 * (roro(p * 2, k - 1) * .5);
}


LL bm(LL n, LL p, int m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

LL n, k, v, c, a, b;

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    cin >> n >> k;
    if(n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    n %= mod;
    v = bm(2, k + 1, mod) * n; v %= mod;
    c = bm(2, k, mod) - 1; c %= mod;
    cout << (mod + v - c) % mod << endl;
//
//    int x, y;
//
//    FOR(i,0,2)
//    cout << roro(2, i) - rec(2, i) << ' ' << roro(3, i) - rec(3, i) << ' ' << roro(7, i) - rec(7, i) << endl;
//
//    FOR(i,0,2)
//    cout << rec(2, i) << ' ' <<  rec(3, i) << ' ' << rec(7, i) << endl;
//
//    FOR(i,0,2)
//    cout << roro(2, i) << ' ' << roro(3, i) << ' ' << roro(7, i) << endl;

    return 0;
}
