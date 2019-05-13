#include<iostream>

#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int dp[101][901][101], n, s, arr[111], l=0 , j=0, lo = 1111;

static int t = 0;


int rec( int x, int y, int z )
{
    if( y == 0 && z == n )
        return 1;
    if( y == 0 && z != n )
        return 0;
    if( x > y )
        return 0;
    if( z > n )
        return 0;
    if( x == 10 )
        return 0;
    if( dp[x][y][z] != -1 )
        return dp[x][y][z];
    else
    {
        dp[x][y][z] = rec( x, y-x, z+1) + rec( x+1,y,z);
        return dp[x][y][z];
    }
}
void prin( int x, int y, int z )
{
    if( y == 0 && z == n )
        return ;
    if( y == 0 && z != n )
        return ;
    if( x > y )
        return ;
    if( z > n )
        return ;
    if( x == 10 )
        return ;
    else
    {
        //x = rec( x, y-x, z+1) + rec( x+1,y,z);

       if( rec(x,y-x,z+1) != 0 )
       {
           if( x == 0 )
           {
               lo = t;

           }
           if( x != 0 && lo == t-1)
           {
               l = t;

           }
           arr[t] =  x ;
           t++;
           prin(x,y-x,z+1);

       }
       else
          prin( x+1,y,z);

    }
}

int main()
{
    ios::sync_with_stdio(false);

    long long int x, i;

    while( cin >> n >> s )
    {
         memset( dp, -1, sizeof(dp));
         t = 0;
         lo = 1111;
         x = rec( 0, s, 0);

         prin( 0, s, 0);

         if( n == 1 && s == 0 )
            cout << 0 <<' ' << 0 <<endl;
         else if( x == 0 )
            cout << -1 <<' ' << -1 <<endl;
         else
            {
                for( i=0; i<t; i++)
                   {
                       if( lo != 1111 && i == 0 )
                       {
                          cout << 1;
                       }
                       else if( lo != 1111 && i == l )
                       {
                          cout << arr[l]-1;
                       }
                       else
                        cout << arr[i];
                   }
                 while( i < n )
                 {
                     cout << 0;
                     i++;
                 }

                   cout << ' ';

               for( i = t-1; i >= 0; i--  )
                   cout << arr[i];
                while( t < n )
                 {
                     cout << 0;
                     t++;
                 }

               cout << endl;
            }
    }


    return 0;

}
