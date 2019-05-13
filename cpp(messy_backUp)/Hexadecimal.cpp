#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int a, b, c, d, e, f;

long long int fn( long long int n, long long int dp[] ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if( dp[n] != -1 )
        return dp[n] % 10000007;
    else
    {
        dp[n] = ( fn(n-1,dp) % 10000007  + fn(n-2,dp) % 10000007 + fn(n-3,dp) % 10000007 + fn(n-4,dp) % 10000007+ fn(n-5,dp) % 10000007 + fn(n-6,dp) % 10000007 );
        return dp[n];
    }

}

 int main() {

    //ios::sync_with_stdio(false);
    long long int n, caseno = 0, cases, ans;
    scanf("%lld", &cases);
    while( cases-- ) {
            long long int dp[10000+5] ;
            memset(dp,-1,sizeof(dp));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        ans = fn(n, dp) % 10000007;
        printf("Case %lld: %lld\n", ++caseno, ans );
    }
    return 0;
}
