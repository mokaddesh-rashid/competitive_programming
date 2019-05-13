#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          (LL)1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

LL bm(LL n, LL p, LL m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

LL modinv( LL n, LL p )
{
    return bm( n, p-2, p );
}

string text, pattern;

int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, x, y, n, m, k, p_val = 0, a, b, c, chk = 0, cnt = 0;
    n = 2;
    cin >> text >> pattern;

    n = text.size();
    m = pattern.size();
    x = m-1;

    FOR(i,0,m-1)
    {
       a = bm(26, x, mod);
       b =  pattern[i]-'a';
       c = a*b;
       p_val += c;
       p_val %= mod;
       x--;
    }
    ///cout << p_val << endl;
    j = 0;
    x = m-1;
    FOR(i,0,m-1)
    {
      a = bm(26, x, mod );
      b = text[i]-'a';
      c = a*b;
      chk += c;
      chk %= mod;
      x--;
    }
    ///cout << chk << endl;
    x = m-1;
    if( chk == p_val ) cnt++;
    FOR(i,m,n-1)
    {
       a =  bm( 26, x, mod);
       b = text[i-m]-'a';
       c = a*b;
       chk -= c;
       chk %= mod;
       chk *= 26;
       chk += text[i]-'a';
       chk %= mod;
       if( chk == p_val ) cnt++;
    }
    cout << cnt <<endl;
    return 0;

}
