#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int cost[50],dp[50][50]={0}, n, weight[50], k;

int rec( int x, int y)
{
    if( x == n )
        return 0;
    if( y+weight[x] >k )
        return 0;
    if( dp[x][y] != 0 )
         return dp[x][y];
    else
    {
        dp[x][y] = max( cost[x]+ rec(x+1, y+weight[x]),rec(x+1, y) );

        return dp[x][y];
    }
}



int main()
{
    ios::sync_with_stdio(false);


    int  i, j,  x;

    cin >> n >> k;

    for( i=0; i<n; i++)
        cin  >> cost[i] >> weight[i];

     x = rec( 0,0);

     cout << x;


}

