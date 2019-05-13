#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int  dp[10000+5][105], k, n, arr[10000+5], l, e=0;

long long int  rec( long long int  x, long long int  y)
{
    if ( x == n && y % k == 0)
      {
         return 1;


      }
    if ( x == n )
        return 0;
    if( dp[x][y] != -1 )
        return dp[x][y];
    else
    {
        long long int  a, b, c;
        a = y + arr[x];

        if( a < 0 )
        {
            c = a % k;
            c += k;
            a = c;
        }
        else
            a %= k;

        b = y - arr[x];

        if( b < 0 )
        {
            c = b % k;
            c += k;
            b = c;
        }
        else
            b %= k;

        if( x == 0)
            dp[x][y] = rec( x+1, a);
        else
            dp[x][y] = max(rec( x+1, b) ,rec( x+1, a));

        return dp[x][y];

    }
}
 int main()
{
    ios::sync_with_stdio(false);

    long long int  t;

    cin >> t;

    while ( t-- )
    {

      long long int  x, b, c;

       cin >> n >> k ;

    //cout << n << ' ' << k <<endl;

    for(long long int  i=0; i<n; i++)
       {
           cin >> b;
           if( b < 0 )
        {
            c = b % k;
            c += k;
            b = c;
        }
        else
            b %= k;

         arr[i] = b;



       }


    memset( dp,-1,sizeof(dp));

     x = rec( 0,0);

     if( x == 0)
        cout << "Not divisible" <<endl;
     else
        cout << "Divisible" <<endl;
    }

    return 0;

}
