#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define INF          freopen("input.txt", "r", stdin);
#define OUTF          freopen("output.txt", "w", stdout);
#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)


//set<int>::iterator ii;


int dp[5005][5005];
int arr[5005];
int n;

int rec( int x, int y )
{
    if( x >= y )
        return 0;
    else if ( 2*x >= y )
        return 0;
    if( dp[x][y] != -1 )
        return dp[x][y];
    else
    {
         int temp;

         temp = min( arr[x] + rec(x+1,y), arr[y] + rec(x,y-1) );
         temp = min( temp, arr[x] + arr[y] + rec(x+1,y-1) );

         dp[x][y] = temp;

         return dp[x][y];
    }
}


int main()
{
    ios::sync_with_stdio(false);

    INF;
    OUTF;

    int i, j, x, y, m;

    cin >> n ;

    memset( dp, -1, sizeof(dp));
    memset( arr, 0, sizeof(arr));


    for( i=0; i<n; i++)
    {
        cin >> x;
        arr[x]++;
    }

    x = rec( 0, 5000);

    cout << x << endl;

    return 0;

}

