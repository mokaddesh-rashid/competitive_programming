#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

long long int dp[50][50]={0}, n, k=3;

long long int rec(long long int x, long long int y, long long int la)
{


    if( y == n )
        return 1;
    if( dp[x][y] != 0 )
        return dp[x][y];
    else
    {
       for(long long int i=0; i<k; i++)
       {
          if( y == n-1 && i == 2)
                break;

          else if( x != i && la != i )
               {
                   if( i == 2)
                      dp[x][y] += rec( i, y+1, x);
                  else
                      dp[x][y] += rec( i, y+1, i);

               }
       }
       return  dp[x][y];
    }
}




int main()
{
    ios::sync_with_stdio(false);

    long long int x;

    cin >> n ;

     x =  rec(2,0,2);

     cout << x;



}

