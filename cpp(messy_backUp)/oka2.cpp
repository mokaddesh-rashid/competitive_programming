#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(short i=j;i<=k;i++)
#define REV(i,j,k) for(short i=j;i>=k;i--)
#define FORR(i,j,k,l) for(short i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prshortf
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
typedef pair<short,short> PR;

short dp[501][501][35][35], n, m;

short rec(short p,short q,short xo,short yo)
{
    short &temp = dp[p][q][xo][yo];
    if(temp  != -1) return temp;

   /// cout << p << ' ' << q << ' ' << xo << ' ' << yo << endl;

    temp = 0;
    if(p >= xo && q >= yo)
    {
        short nx = xo, ny = yo;

        if(nx == ny) nx++, ny = 0;
        else ny++;

        short ans = 1 + rec(p - xo, q - yo, nx, ny);
        temp = max(temp, ans);

    }
    if(p >= yo && q >= xo)
    {
        short nx = xo, ny = yo;

        if(nx == ny) nx++, ny = 0;
        else ny++;

        short ans = 1 + rec(p - yo, q - xo, nx, ny);
        temp = max(temp, ans);
    }
    if(p >= xo + yo && q >= xo + yo)
    {
        short nx = xo, ny = yo;

        if(nx == ny) nx++, ny = 0;
        else ny++;

        short ans = rec(p - yo - xo, q - xo - yo, nx, ny);
        if(xo == yo) ans++;
        else ans += 2;
        temp = max(temp, ans);
    }
    if(xo < 35)
    {
        short ans = rec(p, q, xo + 1, 0);
        temp = max(temp, ans);
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

   mem(dp, -1);
   short tc;

   cin >> tc;

   FOR(tt,1,tc)
   {
        cin >> n >> m;
        cout << "Case #" << tt << ": " << rec(n, m, 1, 0) << endl;
   }

    return 0;
}
