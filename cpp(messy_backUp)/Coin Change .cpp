#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int arr[11] = {50, 25, 10, 5, 1}, n=5, k, dp[6][8888] ={0};

int rec( int x, int y)
{

    if( x == n )
        return 0;
    if( y == 0 )
        return 1;
    if( y < 0 )
        return 0;
    if( dp[x][y] != 0)
        return dp[x][y];
    else
    {
       dp[x][y]= rec( x, y-arr[x]) + rec( x+1, y);
       return dp[x][y];
    }
}


int main()
{
    ios::sync_with_stdio(false);

     while( cin >> k )
     {

     int x;

     x = rec(0,k);

     cout << x <<endl;
     }


}

