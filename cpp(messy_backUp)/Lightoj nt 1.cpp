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
#define sf(n)       scanf("%llu", &n)
#define sff(a,b)    scanf("%llu %llu", &a, &b)
#define mn          (unsigned long long )-1000000000000000000
#define mx          (unsigned long long ) 1000000000000000000


//set<int>::iterator ii;



int   arr[5000000+1], np, pfac[20+1], tim[20+1], nf, nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( int  n )
{
    int   m = sqrt(n), i, j;
    //prime[np] = 2;
   // np++;
    for( i=2; i<=m; i ++)
    {
        if( arr[i] == 0 )
         {
            for( j=i ; j<=n; j += i )
                arr[j] = i ;
         }
    }

    for( i=3 ; i <= n; i += 2)
    {
        if( arr[i] == 0 )
         {
            arr[i] = i;
         }
    }


}



void prime_fac( int   n )
{
   // unsigned long long   m = sqrt(n);

     while( n > 1 )   //for( int   i=0; i<np && prime[i] <= m ; i++ )
    {

           if( pfac[nf-1] == arr[n] )
           {
               tim[nf-1]++;
           }
           else
           {
               pfac[nf] = arr[n];
               tim[nf] = 1;
               nf++;
           }
           n /= arr[n];

    }

}



unsigned long long  fi( unsigned long long  x ) /// coprime bahir kore x
{
    unsigned long long  y = x, i = 0;

    while( i != nf )
    {
            y = y/pfac[i];
            y = y*(pfac[i] - 1);

        i++;
    }

    return y;
}

unsigned long long  k = 4000001, sum[5000003], j = 0;

int main()
{
   // ios::sync_with_stdio(false);
       // inf;
       // outf;
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0

        sieve(5000001); /// range of the sieve


        unsigned long long  n , x, y=0, i, m;

        for( i=1; i<5000001; i++ )
        {
            nf = 0; /// number of fac intially zero
            prime_fac( i );
            x = fi( i );
            y += ( x*x );
            sum[i] = y;
        }


        int t, ca = 1;

        //cin >> t;
        sf( t );
        while( t-- )
        {
            //cin >> x >> y;
           sff( x, y );
           pf( "Case %d: %llu\n", ca++, sum[y] - sum[x-1] );
        }





}




