#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int n, k, arr[22][22], dp[50][50];

int rec( int x, int y)
{
    if( x == n && y <= k )
    {
        return y;
    }

    if( y > k )
        return 0;
    if( x == n )
        return 0;
    if( dp[x][y] != 0 )
        return dp[x][y];
    else
    {
        for(int i=1; i<=arr[x][0]; i++)
        {
            dp[x][y] = max(dp[x][y], rec(x+1, y+arr[x][i]));
        }

        return dp[x][y];
    }
}

int main()
{
    ios::sync_with_stdio(false);

     int t;

     cin >> t;

     while( t-- )
     {
         cin >> k >> n;

     for(int i=0; i<n; i++)
     {
         cin >> arr[i][0];

         for(int j=1; j<=arr[i][0]; j++)
         {
             cin >> arr[i][j];
         }
     }

     int x;

     memset( dp, 0,sizeof(dp));

     x = rec( 0,0);

      if( x == 0 )
        cout << "no solution\n";
      else
        cout << x << endl ;
     }

    return 0;

}

