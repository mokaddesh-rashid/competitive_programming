#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
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
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int dp[30010][345], ar[30001], d, n;

int rec( int x, int y )
{
    int temp;
    if( x > 30000 ) return 0;
    if( dp[x][y] != -1 ) return dp[x][y];
    if( x == 0 ) return dp[x][y] = ar[x]+rec(x+d,y);
    else
    {
        //int a = max( d+y-1, 1 );
        temp = max( ar[x]+rec(x+d+y,y), ar[x]+rec(x+d+y+1,y+1) );
        if( d+y-1 >= 1 ) temp = max( temp, ar[x]+rec( x+d+y-1, y-1 ) );
        return dp[x][y] = temp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, m, a;
    mem( dp, -1 );

    cin >> n >> d ;
    FOR(i,0,n-1)
    {
       cin >> a;
       ar[a]++;
    }
    cout << rec( 0, 0 );
    return 0;

}


