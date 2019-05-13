#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>

int dp[50][50]={0}, n, k;

int rec(int x, int y)
{
    int a;

    if( x == 0 )
        a = 1;
    else
        a = 0;

    if( y == n )
        return 1;
    if( dp[x][y] != 0 )
        return dp[x][y];
    else
    {
       for(int i=a; i<k; i++)
       {
           dp[x][y] += rec( i, y+1);
       }
       return  dp[x][y];
    }
}


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int x;

    cin >> n >> k;

     x =  rec(0,0);

     cout << x;



}

