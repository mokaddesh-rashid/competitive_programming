#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int dp[100+5][100+5], len, arr[100+5], n;


long long int rec ( long long  int x, long long  int y )
{
    if( y - x <= 1 )
       {
        // cout << x << ' '<<y <<endl;
         return 0;
       }
    if ( dp[x][y] != -1 )
        return dp[x][y];

    else
    {
        long long int temp=0;

        for( int i = x+1 ; i < y ; i++ )
        {
           // cout << x <<' '<< i << ' '<<y <<endl;
            temp =   rec( x, i ) + rec( i, y )  + (arr[y] - arr[x]);

            if( i == x+1 )
                dp[x][y] = temp;
            else
                dp[x][y] = min( dp[x][y] , temp);
        }
         return dp[x][y];
    }
}

int main()
{
    ios::sync_with_stdio(false);



    while ( cin >> len  )
    {
        if( len == 0 )
            break;

    long long int i, j, x, y, m;

    cin >> n ;

    for( i=1; i<=n; i++)
        cin >> arr[i];

    arr[n+1] = len;

    memset( dp, -1, sizeof(dp));
    x = rec( 0, n+1);

    cout <<"The minimum cutting is "<< x <<'.'<<endl;

    }

     return 0;

}

