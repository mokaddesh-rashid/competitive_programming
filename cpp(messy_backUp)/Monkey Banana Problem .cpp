#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int  n;

int rec(int x, int y, int a, int fu[][1111], int dp[][1111])
{
    if( y < 0)
        return 0;
   else if( fu[x][y] == 0 )
        return 0;
   else if ( dp[x][y]  != 0 )
      return dp[x][y];
   else if( a < n )
   {
       dp[x][y] = fu[x][y] + max( rec(x+1,y,a+1,fu,dp),rec(x+1,y+1,a+1,fu,dp));

       return dp[x][y];
   }
   else
   {

       dp[x][y] = fu[x][y] + max( rec(x+1,y,a+1,fu,dp), rec(x+1,y-1,a+1,fu,dp));

       return dp[x][y];
   }
}




int main()
{
    ios::sync_with_stdio(false);

    int t, ca=1;

    cin >> t;

    while(t--)
    {
       int fu[1000][1111] = {0},i, j, b, c=1, a=1, ans,dp[1000][1111] = {0};

    cin >> n;

    for( i=0; i<2*n-1; i++ )
    {
        for( j=0; j<c; j++)
        {
            cin >> fu[i][j];
        }

        if( i < n-1)
            c++;
        else
            c--;

    }

    ans = rec(0,0,1,fu,dp);

    cout <<"Case "<<ca<<": "<<ans<<endl;
    ca++;
    }


    return 0;





}

