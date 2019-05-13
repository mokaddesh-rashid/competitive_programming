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
#define M          1000000007
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
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int bm(int b,int p)
{

    if(p == 0) return 1;

    LL ret = bm(b, (p>>1)); ret *= ret; ret %= M;
    if(p%2) {ret *= b; ret %= M;}

    return ret;
}
int modinv(int n) {return bm(n, M-2);}

int fac[MAX], inv[MAX];

void init()
{
    LL v = 1;
    FOR(i,1,MAX-1)
    {
        v = (LL)v * i; v %= M;
        fac[i] = v; inv[i] = modinv( v );
    }
    fac[0] = 1; inv[0] = 1;
}

int nCr(int n,int r)
{
    if(n < r) return 0;

    LL ret = (LL)fac[n] * inv[r]; ret %= M;
    ret = (LL)ret * inv[n - r]; ret %= M;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    init();
    return 0;
}


