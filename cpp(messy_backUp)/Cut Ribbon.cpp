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

long long dp[1000000+2], arr[1000000+5], mx , a, b, c;

long long rec( long long x )
{
    if( x == 0 )
        return 0;
    if( x < 0 )
        return -1111111;
    if( dp[x] != -1 )
        return dp[x];
    else
    {
        long long temp;

        temp = max( 1+rec( x-a ) , 1+rec( x-b ) );
        temp = max( temp , 1+rec( x-c ) );

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
    long long i, j, x, y, n, m;

    cin >> x >> a >> b >> c;

     x = rec(x);

     cout << x << endl;




    return 0;

}



