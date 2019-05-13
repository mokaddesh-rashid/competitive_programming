#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int dp[10000+5][100+5], k, n, arr[10000+5], l;

long long int rec( long long int x, long long int y, long long int z)
{
    if ( y % k == 0 && z == n)
       return 1;
    if ( x == n )
        return 0;
    if( )
    if (dp[x][y] != -1 )
        return dp[x][y];
    else
    {
        if( x == 0 )
            dp[x][y] =  rec( x+1, (y+arr[x])%k, z+1);
        else
          dp[x][y] = rec( x+1, (y-arr[x]) % k, z+1) + rec( x+1, (y+arr[x])%k, z+1);

        return dp[x][y];

    }
}
 int main()
{
    ios::sync_with_stdio(false);

    long long int t, a;

    cin >> t;

    while ( t-- )
    {

      long long int x;
       cin >> n >> k ;

    //cout << n << ' ' << k <<endl;

    for(long long int i=0; i<n; i++)
       {
           cin >> a;
           arr[i] = a%k;
       }
      l = n;
    memset( dp,-1,sizeof(dp));

    x = rec( 0,k,0);

    if( x != 0 )
        cout << "Divisible\n";
    else
         cout << "Not divisible\n";
    }

    return 0;

}
