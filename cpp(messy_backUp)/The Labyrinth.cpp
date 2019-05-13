#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


char str[1001][1001];

int dp[100+1][100+1], n, m, has[1001][1001];

int rec( int x, int y)
{
    if( x < 0  )
        return 0;
    if( y < 0 )
         return 0;
    if(  x == n )
        return 0;
    if( y == m )
        return 0;
    if( str[x][y] == '*' )
        return 0;

    if(dp[x][y] != -1)
        return dp[x][y];
    else
    {
        //cout << 'j';
        has[x][y]++;
        //dp[x][y] = 1 + rec(x,y-1)+ rec(x-1,y) + rec(x,y+1) + rec(x+1,y);
        //dp[x][y] ;
        return 1 + rec(x,y-1)+ rec(x-1,y) + rec(x,y+1) + rec(x+1,y);;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    memset(dp,-1,sizeof(dp));

    int i, j, a, b;

    cin >> n >> m;

    for( i=0; i<n; i++)
        cin >> str[i];

    //cout << str[0][0];

    for( i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
        {

            if( str[i][j] == '*' )
            {
                memset(has,-1,sizeof(has));
                int x = i, y= j;
                has[x][y]++;
                dp[x][y] = 1 + rec(x,y-1)%10 + rec(x-1,y)%10 + rec(x,y+1)%10 + rec(x+1,y)%10;


                cout << dp[x][y]%10;

            }
            else
                cout<<'.';
        }

        cout << endl;
    }






}

