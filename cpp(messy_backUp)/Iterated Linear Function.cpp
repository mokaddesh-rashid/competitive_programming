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
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000007
#define LL           long long
#define NL '\n'


//set<int>::iterator ii;

LL bm(LL n, LL p, int m)
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



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b, c, A, B, z, v;

    cin >> A >> B >> n >> x ;

    n = n % mod;

    y = bm( A, n, mod ) ;
    y %= mod;
    y = y*x;
    y %= mod;


        z = bm( A, n, mod ) - 1;
        v = modinv( A-1, mod );
        v = v*z;
        v %= mod;
        v = v*B;
        v %= mod;


    if( A == 1 )
        cout << ( A + n )%mod;
    else
        cout << (y+v)%mod;


    return 0;

}


