#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int dp[100+1][1+50000], k, n, arr[100+1], l;

long long int rec( long long int x, long long int y, long long int z)
{

    if ( x == n )
        return max( y-z,z-y);
    if( dp[x][y] != -1)
        return dp[x][y];
    else
    {

        dp[x][y] = min(rec( x+1, y-arr[x], z+arr[x]) , rec( x+1, y, z) );

        return dp[x][y];

    }
}
 int main()
{
    ios::sync_with_stdio(false);

    long long int t;

    cin >> t;

    while ( t-- )
    {

      long long int x;
       cin >> n;

    //cout << n << ' ' << k <<endl;
     l = 0;
    for(long long int i=0; i<n; i++)
        {
            cin >> arr[i];
            l += arr[i];
        }



    memset( dp,-1,sizeof(dp));

    x = rec( 0,l,0);

    cout << x << endl;

    }

    return 0;

}
