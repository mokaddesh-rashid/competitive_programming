#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


int dp[101][101][101];

int i, j, x, y, n, m, w, k, a;

int  arr[111], cover[221], max_li[211], min_li[111];

int rec( int x, int y, int z)
{
    if( x == n )
        return 0;
    if( z == k )
        return 0;
    if( dp[x][y][z] != -1 )
        return dp[x][y][z];
    else
    {
        int cov=0;

        for (int i=0; i<n; i++)
    {
             if( z != 0 && min_li[i] >= min_li[y] && min_li[i] <= max_li[y])
             {
                 continue;
             }
            else if( min_li[i] >= min_li[x] && min_li[i] <= max_li[x] )
                cov++;

    }


        dp[x][y][z] = max ( rec ( x+1, x, z+1 ) + cov, rec( x+1, y, z )  );

        return dp[x][y][z];
    }


}

int main()
{
    ios::sync_with_stdio(false);


    int t, ca=1;

    cin >> t;

    while ( t-- )
    {
        int x;

    cin >> n >> w >> k;




     memset( dp, -1, sizeof(dp));

    for( i=0; i<n; i++)
    {
       cin >> a >> min_li[i] ;
    }

    sort ( min_li, min_li+n);

     for( i=0; i<n; i++)
    {
       max_li[i] = w + min_li[i] ;
    }

     x = rec ( 0,0,0);

     cout << "Case "<<ca<<": "<<x<<endl;
     ca++;
    }



    return 0;

}

