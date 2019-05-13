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


//set<int>::iterator ii;

int arr[1000010], dp[1010][1010][2], n, m;

int rec( int x, int y, int z )
{
   // cout << y << endl;
    if( y % m == 0 && z != 0 )
        return 1;
    if( x == n )
        return 0;
    if( dp[x][y][z] != -1)
        return dp[x][y][z];
    else
    {
        dp[x][y][z] = max( rec( x+1 , ( y + arr[x] ) % m, 1 ), rec(x+1, y%m , max(z,0) ) );
        return dp[x][y][z];
    }
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( dp, -1, sizeof(dp));
    int i, j, x, y;

    cin >> n >> m ;

    for( i=0; i<n; i++)
        cin >> arr[i];

    if( n >= m )
        cout << "YES";

    else
    {
        x = rec(0,0,0);

    if( x == 1 )
        cout << "YES";
    else
        cout << "NO";
    }



    return 0;

}


