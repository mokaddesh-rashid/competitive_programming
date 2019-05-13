#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;

int arr[1000], dp[110][1000], n;
string str;

int rec( int x, int y )
{
    if( y % 8 == 0 && y != 0 )
        return 1;
    if( y > 999 )
        return 0;
    if( x == n )
        return 0;
//    if( dp[x][y] != -1 )
//        return dp[x][y];
    else
    {
        int val = str[x]-48;

        if( y == 0 )
            dp[x][y] = max( rec( x+1, val ) , rec( x+1, y ) );
        else
            dp[x][y] = max( rec( x+1, y*10+ val ) , rec( x+1, y ) );

        return dp[x][y];
    }


}

void prin(int x, int y)
{
    if( y % 8 == 0 && y != 0 )
        return ;
    if( y > 999 )
        return ;
    if( x == n )
        return ;
    else
    {
             int val = str[x]-48;
             if( y == 0 )
           {
               if( rec( x+1, val ) > rec( x+1, y ) )
               {
                  cout << str[x];
                  prin( x+1, val );
               }
               else
               {
                   prin( x+1, y );
               }
              //dp[x][y] = max( rec( x+1, val ) , rec( x+1, y ) );
           }
        else
        {
            {
               if( rec( x+1, y*10+ val ) > rec( x+1, y ) )
               {
                  cout << str[x];
                  prin( x+1, y*10+ val );
               }
               else
               {
                   prin( x+1, y );
               }
              //dp[x][y] = max( rec( x+1, y*10+ val ) , rec( x+1, y ) );
           }
        }

    }
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    memset( dp, -1, sizeof(dp));

    int i, j, x, y = 0;

    cin >> str ;

    n = str.size();

    for( i=0; i<n; i++)
    {
        if( str[i] == '0' )
            y = 1;
    }

    if( y == 1 )
    {
        cout << "YES\n0";
    }

    else
    {
        x  = rec( 0, 0);

    //cout << x;

    if( x == 0 )
        cout << "NO";

    else
    {
        cout << "YES\n";
        prin( 0, 0);
    }
    }



    return 0;

}


