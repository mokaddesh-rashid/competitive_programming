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


//set<int>::iterator ii;

long long int dp[5005][5005], n, arr[5005], m , k;

long long int rec( long long int x, long long int y )
{
    if( y/m == k )
        return 0;
    if( x == n )
        return (long long)-1000000000000000007;
    if(dp[x][y] != -1 )
        return dp[x][y];
    else if( y%m )
    {
        long long int temp = arr[x] + rec( x+1, y+1);
        dp[x][y] = temp;
        return dp[x][y];
    }
    else
    {
        long long int temp = max ( arr[x] + rec( x+1, y+1) , rec( x+1 , y ) );
        dp[x][y] = temp;
        return dp[x][y];
    }
}



int main()
{
    ios::sync_with_stdio(false);

    //INP;
    //OUT;

    long long int i, j, x, y;

    cin >> n >> m >> k;

    memset( dp, -1, sizeof(dp));

    for( i=0; i<n; i++)
        cin >> arr[i];

    x = rec( 0, 0);

    cout << x;

    return 0;

}


