
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str,ss;
int n,m,dp[5+1000][5+1000];


int rec(int x, int y)
{


    if( x == n )
    return 0;
    if (y == -1)
    return 0;
    if( dp[x][y] != -1 )
       return dp[x][y];
    if( str[x] == ss[y] )
        {
            dp[x][y] = 1 + rec( x+1,y-1) ;
            return dp[x][y];
        }

    else
    {

          dp[x][y] = max( rec(x,y-1), rec(x+1,y) );
          return dp[x][y];

    }
}





int main()
{

    int x, t, a=0;

    cin >> t;

    cin.ignore();

    while( t--  )

     {
         getline(cin, str);
         ss = str;
         n = str.size();
         m = ss.size();

     memset( dp,-1,sizeof(dp));

     x = rec(0,m-1);

     cout << x <<endl;

     }
}

