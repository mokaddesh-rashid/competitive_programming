#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int  n;

long long int rec(long long int x, long long int y, long long int la,long long int arr[][200],long long int dp[][500] )
{

    long long int a = 0, b=0, c=0, i;
    if( y == n )
        return 0;
    if( dp[x][y] != 0 )
        return dp[x][y];
    if( y == 0 )
    {
        a = arr[0][0] + rec( 0, y+1, 0,arr,dp);
        b = arr[0][1] + rec( 1, y+1, 1,arr,dp);
        c = arr[0][2] + rec( 2, y+1, 2,arr,dp);

        a = min( a, b);
        //dp[x][y] = min( dp[x][y], c);

        return min(a,c);



    }
    else
    {
        //cout <<'h'<<endl;
       for(long long int i=0; i<3; i++)
       {
           if( x != i && a == 0  )
               {
                     a = arr[y][i] +rec( i, y+1, i,arr,dp);

               }
           else if(  x != i )
           {
                b = arr[y][i] + rec( i, y+1, i,arr,dp);
           }

       }

        dp[x][y] = min(a,b);

       return  dp[x][y];
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t, ca=1;

    cin >> t;

    while( t-- )
    {
        long long int i, j, a, b, x=0;
        long long int arr[200][200]={0}, dp[500][500]={0};

       cin >> n;

    for( i=0; i<n; i++)
    {
        for( j=0; j<3; j++)
              cin >> arr[i][j];
    }

    x = rec( -1,0,-1,arr,dp);

    cout <<"Case "<<ca<<":  "<< x<<endl;
    ca++;

    }





}
