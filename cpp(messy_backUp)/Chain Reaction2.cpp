#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define INF          freopen("in.txt", "r", stdin);
#define OUTF          freopen("out.txt", "w", stdout);
#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)


//set<int>::iterator ii;

int dp[1000000+2], arr[1000000+5], mx ;

int rec( int x )
{
    if( x < 0 )
        return 0;
    if( dp[x] != -1 )
        return dp[x];
    else
    {
        int temp;

        if( arr[x] != 0 )
            temp = 1 + rec( x-arr[x]-1 );
        else
            temp = rec( x-1 );

        dp[x] = temp;

        return dp[x];
    }
}


int main()
{
    ios::sync_with_stdio(false);

    //INP;
    //OUT;
    memset( dp, -1, sizeof(dp));
    memset( arr, 0, sizeof(arr));
    mx = -1;
    int i, j, x, y, n, m, a = 0;

    cin >> n ;

    for( i=0; i<n; i++)
    {
        cin >> x >> y;
        arr[x] = y;

        mx = max(x, mx);
    }

    for( i=mx; i>=0; i-- )
    {
        if( arr[i] != 0 )
        {
           x = rec(i);
          // cout << x << endl;
           a = max( x, a);

        }
    }

     cout << n-a << endl;




    return 0;

}

