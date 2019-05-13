
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str,ss;
int n,m,dp[5+1000][5+1000],arr[1111],brr[1111], xx=0;


int rec(int x, int y)
{


    if( x >= y )
      return 0;
    if( dp[x][y] != -1 )
       return dp[x][y];
    if( str[x] == str[y] )
        {
            dp[x][y] = 1 + rec( x+1,y-1);
            dp[x][y]  += rec(x+1,y);
            dp[x][y]  += rec(x,y-1);
            xx += 3;
            return dp[x][y];
        }

    else
    {
          dp[x][y]  += rec(x+1,y);
          dp[x][y]  += rec(x,y-1);
          dp[x][y]  += rec(x+1,y-1);
          xx += 3;

          return dp[x][y];

    }
}





int main()
{

    int x, ca = 1, t;

    cin >> t;

    cin.ignore();

    while( t-- )

     {
         getline(cin, str);
         n = str.size();
        // m = ss.size();
        // cout << n << endl;

     memset( dp,-1,sizeof(dp));

     x = rec(0,n-1);

     cout<< "Case "<<ca<<": "<< x <<endl;
     ca++;
     }
}
/*
tanbirahmed
shahriarmanzoor
monirulhasan
syedmonowarhossain
sadrulhabibchowdhury
mohammadsajjadhossain
*/
