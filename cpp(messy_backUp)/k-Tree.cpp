#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int n, k, d, dp[111][111][3];

int rec( int x, int y, int z )
{
    //cout << x << ' ' << y << ' ' << d << endl;
    int temp = 0, p = 0;

    if( x < 0 )
        return 0;
    if( x == 0 && z == 1 )
        return 1;
    if( x == 0 )
        return 0;
    if( dp[x][y][z] != -1 )
        return dp[x][y][z];
    else
    {
        for( int i=1; i<=k; i++ )
        {
            if( i >= d && z == 0 )
                temp += rec( x-i, i, 1 );
            else//cout << i << ' ' << z << endl;
                temp += rec( x-i, i, z );
            temp %= mod;
        }
        dp[x][y][z] = temp;
        return dp[x][y][z];
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( dp, -1, sizeof(dp) );
    int i, j, x, y, m;

    cin >> n >> k >> d;

    cout << rec( n, 0, 0 );

    return 0;

}


