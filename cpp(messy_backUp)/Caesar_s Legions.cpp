#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000
#define mod          100000000


//set<int>::iterator ii;

int  dp[110][110][2][11], n, n1, n2, k1, k2;

int  rec( int  x, int  y, int  z, int  k ) /// x is number of 1st type soldier,  y is number of 2st type soldier, z is type of last soldier
{
    long long ans;
    if( x > n1 )
        return 0;
    if( y > n2 )
        return 0;
    if( x == n1 && y == n2 )
       {
            return 1;
       }
    else if( x + y == n )
        return 0;
    else if( dp[x][y][z][k] != -1 )
        return dp[x][y][z][k] % mod;
    else
    {
            if( z == 0 )
            {
                if(  k < k1 ) /// any soldier can take next position
                     {

                           ans = rec( x+1, y, 0, k+1 ) % mod + rec( x, y+1, 1, 1 ) % mod ;


                      }
                else   /// only 2nd type soldier can take next position
                      {

                           ans = rec( x, y+1, 1, 1 );

                      }

            }
            else
            {
                if(  k < k2 ) /// any soldier can take next position
                     {

                         ans = rec( x+1, y, 0, 1 ) % mod + rec( x, y+1, 1, k+1 ) % mod ;

                     }

                else /// only 1st type soldier can take next position
                     {
                         ans =  rec( x+1, y, 0, 1 );

                     }

            }

             dp[x][y][z][k]  = ans % mod;

             return dp[x][y][z][k];

    }
}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int  i, j, x, y;

    memset( dp, -1, sizeof(dp));

    cin >> n1 >> n2 >> k1 >> k2 ;

    n = n1+n2;

    x = rec( 0,0,0,0);
    //y = rec( 0,0,1,0);

     x = x % mod ;

     cout << x;



    return 0;

}


