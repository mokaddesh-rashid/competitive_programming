#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<long long >::iterator ii;



long long  arr[100000+10], prime[100000+10], np, pfac[20+1], tim[20+1], nf, chk[100000+2], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number
void sieve( long long n )
{
    long long  m = sqrt(n), i, j;
    prime[np] = 2;
    np++;
    for( i=3; i<=m; i += 2)
    {
        if( arr[i] == 0 )
         {
            for( j=i*i; j<=n; j += (i+i) )
                arr[j]++;
         }
    }
    for( i=3; i<=n; i += 2)
    {
        if( arr[i] == 0 )
         {
            prime[np] = i;
            np++;
         }
    }


}


int main()
{
    //ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr) );
    np = 0; /// number of prime initially 0

    sieve(100001); /// range of sieve

    long long  t, ca = 1;

    sf( t );

    while( t-- )
    {
        long long  i = 0, j, n, m, a, b, c, d, x, y=0;
    //cin >> n >> m;
    sff( n, m );
    memset( chk, 0, sizeof(chk) );
    while( prime[i] * prime[i] <= m )
    {
        b = n % prime[i];
        if( b != 0 )
        {
            c = b;
            b = prime[i] - b;
        }
        d = n + b;

        while( d <= m )
        {
            //cout << d << ' ';
            x = d - n;
            if( d != prime[i] )
            chk[x]++;
            d += prime[i];
        }
        i++;

    }

    for( i=0; i < m-n+1; i++ )
    {
        if( chk[i] == 0  )
        {
            y++;
        }
    }

    if( n == 1 )
        y--;
    pf( "Case %lld: %lld\n", ca++, y );
    //cout << y ;
    }

}

