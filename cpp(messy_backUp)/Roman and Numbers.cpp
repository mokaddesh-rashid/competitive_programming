
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

set < long long > myset;

int main()
{
     std::ios::sync_with_stdio(false);

     int t;

     cin >> t;

     while( t-- )
     {
         long long  maxx = mn, a, b, m, i , ans, y;

         string str;

         cin >> str;

         cin >> m;

         n = str.size();
         nf = n;

         x = 0;


        for( i=0; i<nf; i++ )
            pfac[i] = str[i] - 48;


        for( long long  bt=0; bt < 1<<nf; bt++ )
          {
            long long  nob = 0;

            long long val = 0, t, c = 0, k;

            for(long long  i=0; i< nf; i++ )
            {


                if( bt & (1<<i) )
                {
                    if( val == 0 )
                        val = pfac[i];
                    else
                    {
                        val *= 10;
                        val += pfac[i];
                    }

                }

            }
            cout << val << ' ';
            if( val % m == 0 )
                 {
                     x++;
                     myset.insert( val );
                 }

          }

          cout << endl << x << endl;



     }



}
