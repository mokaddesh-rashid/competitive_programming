#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str,ss, ans;
int  n, m, dp[5+1000][5+1000], st, en, arr[1000+5] ;


int rec(int x, int y)
{
    int a,b;

    if( x > y )
    return 0;


    if( dp[x][y] != -1 )
       return dp[x][y];

    if( str[x] == str[y] )
       {
           if( x!= y )
           {
               arr[x]++;
               arr[y]++;
           }
           if( x == y )
               dp[x][y] = 1 + rec( x+1,y-1);
           else
               dp[x][y] = 2 + rec( x+1,y-1);

           return dp[x][y];
       }

    else
    {
        dp[x][y]  = max(rec(x,y-1) , rec(x+1,y));

        return dp[x][y];


    }
}

void prin(int x, int y)
{
    int a,b;

    if( x > y )
    return ;

    if( str[x] == str[y] )
       {
          // cout << str[x];
           ans [st] = str[x];
           ans [en] = str[x];
           st++;
           en--;
           prin( x+1,y-1);
       }

    else
    {
        if ( rec(x,y-1) > rec(x+1,y) )
           prin( x, y-1);
        else if ( rec(x,y-1) == rec(x+1,y) && str[x] < str[y] )
           prin( x, y-1);
        else
            prin( x+1, y);


    }
}

int main()
{

    int x,i;

    while( getline(cin, str))

     {
         n = str.size();
         ans = str;
         memset( dp,-1,sizeof(dp));
         memset( arr,-1,sizeof(arr));
         x = rec(0,n-1);

         //cout << x <<' ';

         st = 0;
         en = x-1;
         prin( 0, n-1);
         for( i=0; i<x; i++)
            cout << ans[i];

         cout << endl;



     }

     return 0;
}
