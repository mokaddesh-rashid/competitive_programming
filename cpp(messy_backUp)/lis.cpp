#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


int dp[100][100], arr[100], n, m=0;

int rec( int x, int y )
{
    if( x == n )
        return 0;
    if( dp[x][y] != -1 )
        return dp[x][y];

    else
    {
        if( arr[x] > y  )
            {
                dp[x][y] = 1 + rec( x+1, arr[x] );
                //m++;

            }

        dp[x][y] = max( dp[x][y] , rec(x+1, y));

        return dp[x][y];
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while(true)
    {
         cin >> n;

     memset(dp,-1,sizeof(dp));

     for(int i=0; i<n; i++)
        cin >> arr[i];

     cout << rec(0,0) << endl;

    }


}

