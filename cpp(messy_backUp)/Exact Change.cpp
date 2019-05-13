#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int i, j, n, m, dp[100+2][20000+2], arr[100+2], z, k, len , ans , dpm[100+2][20000+2], xx;

int rec( int x, int y )
{
    if( x == n )
        return z;

    if( y >= k )
        return y;

    if( dp[x][y] != -1 )
        return dp[x][y];

    else
    {
        dp[x][y] = min( rec( x+1, y+arr[x]) , rec( x+1, y ) );

        return dp[x][y];
    }
}

int reccc( int x, int y , int ll)
{
    if( x == n || y > xx )
        return n;

    if( y == xx )
        return ll;


    if( dpm[x][y] != -1 )
        return dpm[x][y];

    else
    {
        dpm[x][y] = min( reccc( x+1, y+arr[x], ll+1 ) , reccc( x+1, y , ll ) );

        return dpm[x][y];
    }
}




int main()
{
    ios::sync_with_stdio(false);

    int t;

    cin >> t;

    while ( t-- )
    {

     cin >> k;

     cin >> n;

     z = 0;

     len = 0;

     memset( dp, -1, sizeof(dp));
     memset( dpm, -1, sizeof(dpm));

     for( i=0 ; i<n ; i++ )
         {
             cin >> arr[i] ;

             z += arr[i];
         }

     xx = rec( 0, 0 );

     len = reccc( 0, 0, 0);

     cout << xx << ' ' << len << endl;

    }


    return 0;

}

