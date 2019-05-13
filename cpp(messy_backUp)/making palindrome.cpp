#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str,ss, ans;
int  n, m, dp[5+1000][5+1000], st, en  ;


int rec(int x, int y)
{
    int a,b;

    if( x > y )
    return 0;


    if( dp[x][y] != -1 )
       return dp[x][y];

    if( str[x] == ss[y] )
       {
           dp[x][y] = rec( x+1,y-1);

           return dp[x][y];
       }

    else
    {
        dp[x][y]  = min(rec(x,y-1) + 1,rec(x+1,y) + 1);

        return dp[x][y];


    }
}

string prin(int x, int y, string str)
{
    int a,b;

    if( x > y )
    {

        if( ans.size() < ans)
        return ;

    }

    if( str[x] == ss[y] )
       {
            ans[st] = ss[y];
            ans[en] = ss[y];
            st++;
            en--;
            prin( x+1,y-1);
       }

    else
    {
        if(rec(x,y-1) + 1 < rec(x+1,y) + 1)
           {
               ans[st] = ss[y];
               ans[en] = ss[y];
                st++;
                en--;
               prin(x,y-1);
           }
        else
           {
                ans[st] = str[x];
                ans[en] = str[x];
                st++;
                en--;
                prin(x+1,y);
           }



    }
}



int main()
{

    int x,i;

    while( getline(cin, str))

     {
         ss = str;
         ans = str + str;
         n = str.size();
         memset( dp,-1,sizeof(dp));
         x = rec(0,n-1);

         cout << x <<' ';

         st = 0;
         en = n + x -1;

         prin(0,n-1);

         for( i=0;i<n+x;i++)
            cout << ans[i];

         cout << endl;



     }

     return 0;
}
