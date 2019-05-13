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
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL n, m, dp[5][10100][5];

LL rec( int x , int y , int z)
{
    //cout << x << ' ' << y << ' ' << z << endl;
    if( x == 0 && z%2 == 0 )  return 1;
    if( x == 0 || y == 0 ) return 0;
    if( dp[x][y][z] != -1 )
        return dp[x][y][z];
    int a = 0;
    if( y%2 ) a++;

    return dp[x][y][z] = rec( x-1, y-1, z+a )+rec( x, y-1, z );


}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( dp, -1, sizeof(dp) );
    LL i, j, x, y, a;

    cin >> n;

    cout << rec( 3, n, 0 );



    return 0;

}

