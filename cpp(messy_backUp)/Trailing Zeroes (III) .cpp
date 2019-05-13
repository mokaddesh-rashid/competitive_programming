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

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


//set<int>::iterator ii;

long long arr[1000000], v;

int chk( long long x )
{
    int cnt = 0;

    for(int i=0; i<12; i++ )
    {
        cnt += ( x / arr[i] );
    }

    if( cnt > v )
        return 1;
    if( cnt == v )
        return 2;

    return 0;
}


int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long i = 0, j, x = 5, y, z, t, ca = 1, low, up, st, en, mid, a;

    while( x < 1000000000 )
    {
        arr[i] = x;
        x *= 5;
        i++;
    }

   //cin >> t;
   sf( t );

   for( i=0; i<t; i++ )
   {

       sf( v );

       st = 0;
       en = 1000000000;
       long long ans = mx;
       while( st <= en )
       {
           mid = ( st + en ) / 2;
           a = chk( mid );
           if( a == 0 )
              st = mid + 1;
           else
              {
                  if( a == 2 )
                    ans = min( ans, mid );
                  en = mid - 1;
              }
       }


         if( ans != mx )
            pf ( "Case %lld: %lld\n", ca++, ans );
         else
            pf ( "Case %lld: impossible\n", ca++ );
   }







    return 0;

}


