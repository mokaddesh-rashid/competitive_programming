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

long long dp[1000000+2], arr[1000000+5], mx ;

long long rec( long long x )
{
    if( x < 0 )
        return 0;
    if( dp[x] != -1 )
        return dp[x];
    else
    {
        long long temp;

        temp = max( arr[x] + rec( x-2 ) , rec( x-1 ) );

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
    long long i, j, x, y, n, m, a = 0;

    cin >> n ;

    for( i=0; i<n; i++)
    {
        cin >> x ;
        arr[x] += x;

        mx = max(x, mx);
    }

     x = rec(mx);

     cout << x << endl;




    return 0;

}


