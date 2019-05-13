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
#define pf          prlong long f
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807


long long int pfac[30000000], nf, arr[30000000], tim[30000000], n, x;


int main()
{
     std::ios::sync_with_stdio(false);

     int t;

     cin >> t;

     while( t-- )
     {
         long long  maxx = mn, a, b, m, i , ans, y;

         cin >> n >> nf;

         x = n;


        for( i=0; i<nf; i++ )
           cin >> pfac[i];


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

                    if( val > (long long) 1000000000000000 )
                             break;
                    //val /= t;

                    nob++;
                }

            }
            if( nob > 0 )
                 {
                     if( nob % 2 )
                        x -= ( n / val );
                     else
                        x +=  ( n / val );
                 }

          }

          cout << x << endl;

     }



}
