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



long long  chk( long long val )
{
    //cout << x << endl;
    long long t = 0;


    for( long long  i=0; i<x; i++ )
    {
        if( tim[i] % 2 )
        {
            //cout << '+' << ' ' << ( val / arr[i] );
            t += (tim[i]*( val / arr[i] )) ;
        }
        else
        {
            //cout << '-' << ' ' << ( val / arr[i] );
            t -= ( tim[i] * ( val / arr[i] ) );
        }
    }
    //cout << val << ' ' << t << endl;
    if( n <= t )
        return 1;
    else
        return 0;
}

int main()
{
     std::ios::sync_with_stdio(false);

     int t;

     cin >> t;

     while( t-- )
     {
         long long  maxx = mn, a, b, m, i , ans, y;

         cin >> nf >> n;

         x = 0;


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
            if( nob > 0 && c == 0 )
                 {
                     arr[x] = val;
                     tim[x] = nob;
                     x++;
                 }

           }

//        for( i=0; i<x; i++ )
//            cout << arr[i] << ' ' << tim[i] << endl;

//        a = chk(6);

        long long st = 0 , en = (long long) 100000000000000, mid;

        ans = mx;

        while( st <= en )
        {

           mid = ( st + en ) / 2;
           // cout << mid << ' ' << a << endl;
           a = chk( mid );

           if( a == 1 )
           {
               en = mid-1;
               ans = min( ans, mid );
           }
           else
               st = mid+1;
        }

    cout << ans << endl;

     }



}
