#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int dp[100+5][100+5], len, arr[100+5], n, k;


long long int rec ( long long  int x, long long  int y )
{
    if( x == k && y == 0 )
       {
        // cout << x << ' '<<y <<endl;
         return 1;
       }
    else if ( x == k )
        return 0;
    else if ( y < 0 )
        return 0;

    if ( dp[x][y] != -1 )
        return dp[x][y] % 1000000;

    else
    {


        for( int i = 0 ; i <= n ; i++ )
        {
            if( i == 0)
                dp[x][y] = rec( x+1, y-i) % 1000000;
            else
                dp[x][y] = ( dp[x][y] + rec( x+1, y-i) ) % 1000000;


        }
         return dp[x][y] % 1000000 ;
    }
}

int main()
{
    ios::sync_with_stdio(false);



    while ( cin >> n >> k  )
    {
        if( n == 0 && k == 0 )
            break;

    long long int i, j, x, y, m;


    memset( dp, -1, sizeof(dp));
    x = rec( 0, n);

     cout << x % 1000000 << endl;
    }

     return 0;

}

