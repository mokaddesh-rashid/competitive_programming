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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int n, arr[10000], dp[111][111];

int rec( int x, int y )
{
    if( x == n )
        return 0;
    //if( dp[x][y] != -1 )
        //return dp[x][y];
    if( y == 0 )
    {
        if( arr[x] == 0 )
        {
            dp[x][y] = 1+rec( x+1, 0 );
            return dp[x][y];
        }
        else if( arr[x] == 1 )
        {
            dp[x][y] = rec( x+1, 2 );
            return dp[x][y];
        }
        else if( arr[x] == 2 )
        {
           dp[x][y] =  rec( x+1, 1 );
            return dp[x][y];
        }
        else if( arr[x] == 3 )
        {
           dp[x][y] =  min( rec( x+1, 2 ), rec(x+1, 1 ) );
            return dp[x][y];
        }

    }
    if( y == 1 )
    {
        if( arr[x] == 0 )
        {
           dp[x][y] =  1+rec( x+1, 0 );
            return dp[x][y];
        }
        else if( arr[x] == 1 )
        {
           dp[x][y] =  rec( x+1, 2 );
            return dp[x][y];
        }
        else if( arr[x] == 2 )
        {
           dp[x][y] =  1+rec( x+1, 0 );
            return dp[x][y];

        }
        else if( arr[x] == 3 )
        {
           dp[x][y] =  min( rec( x+1, 2 ), 1+rec(x+1, 0 ) );
            return dp[x][y];
        }

    }
    if( y == 2 )
    {
        if( arr[x] == 0 )
        {
           dp[x][y] =  1+rec( x+1, 0 );
            return dp[x][y];
        }
        else if( arr[x] == 1 )
        {
           dp[x][y] =  1+rec( x+1, 0 );
            return dp[x][y];
        }
        else if( arr[x] == 2 )
        {
           dp[x][y] =  rec( x+1, 1 );
            return dp[x][y];
        }
        else if( arr[x] == 3 )
        {
           dp[x][y] =  min( 1+rec( x+1, 0 ), rec(x+1, 1 ) );
            return dp[x][y];
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( dp, -1, sizeof(dp) );
    int i, j, x, y, m;

    cin >> n;

    for( i=0; i<n; i++)
        cin >> arr[i];

    x = rec( 0, 0 );

    cout << x << endl;
    return 0;

}


