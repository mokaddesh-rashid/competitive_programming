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
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 1000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL mat[110][110], co[110], dp[110][110][110], n, m, k;

LL rec( int x, int y, int z )
{
    LL temp = maxx;

    if( x == 0 && z == 0 )
        {
            //cout << k << endl;
            return 0;
        }
    if( x == 0 || z < 0 )
        return maxx;
    if( dp[x][y][z] != -1 )
        return dp[x][y][z];
    if( co[x] != 0 )
    {

        if( co[x] == y )
            return dp[x][y][z] = rec( x-1, co[x], z );

            return dp[x][y][z] = rec( x-1, co[x], z-1 );
    }
    else
    {
        for( int i=1; i<=m; i++ )
        {
            if( y == i )
            temp = min( temp, mat[x][i]+rec( x-1, i, z ) );
            else
            temp = min( temp, mat[x][i]+rec( x-1, i, z-1 ) );
        }
        //cout << x << ' ' << y << ' ' << z << endl;
        return dp[x][y][z] = temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);

//    inf;
    //outf;

    LL i, j, x, y ;
    memset( dp, -1, sizeof(dp) );
    cin >> n >> m >> k;

    for( i=1; i<=n; i++ )
        cin >> co[i];

    for( i=1; i<=n; i++ )
    {
        for( j=1; j<=m; j++ )
        {
            cin >> mat[i][j];
        }
    }


    x =  rec( n, 101, k );
    //cout << x << endl;
    if( x >= maxx )
        cout << -1;
    else
        cout << x;
    return 0;

}

