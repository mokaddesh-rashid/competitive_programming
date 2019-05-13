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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807


long long int pfac[300], nf, tim[300], n, x;


int main()
{
     //std::ios::sync_with_stdio(false);

     long long t, ca = 1;

     cin >> t;

     while( t-- )
     {
         long long  maxx = mn, a, b, m, i , ans, y;

         //cin >> n >> nf;
         sff( n, nf );
         x = n;

        for( i=0; i<nf; i++ )
            sf( pfac[i] );
//           cin >> pfac[i];

        for( long long  bt=0; bt < 1<<nf; bt++ )
          {
            long long  nob = 0;

            long long val = 1, t, c = 0, k;

            for(long long  i=0; i< nf; i++ )
            {
                if( bt & (1<<i) )
                {
                    t = __gcd( val,pfac[i] );
                    val /= t;
                    k = val;
                    val *= pfac[i];

                    if( val % pfac[i] != 0 )
                        c = 1;

                    //if( val > n )
                        //c = 1;

                    nob++;
                }

            }
            if( nob > 0 && c == 0 )
                 {
                     if( nob % 2 )
                        x -= ( n / val );
                     else
                        x +=  ( n / val );
                 }

          }

          pf("Case %lld: %lld\n",ca ,x );
          //cout << << x << endl;
          ca++;

     }



}
