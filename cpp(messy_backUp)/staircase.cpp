#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int cost[50],dp[500][500]={0}, n, weight[50], k;

long long int rec( long long int x, long long int y)
{

    long long int a = y/2, i;

    if( y%2  )
        a++;

    if( dp[x][y] != 0 )
        return dp[x][y];
    else
    {
        for(i=x+1 ; i<a; i++)
        {
            //cout << i << ' ' << y-i<< endl;
            dp[x][y] += (rec(i,y-i)+1);
            //dp[x][y]++;
        }
        return dp[x][y];
    }
}



int main()
{
    ios::sync_with_stdio(false);


    long long int  i, j,  x;

    cin >> n;



     x = rec( 0,n);

     cout << x;


}


