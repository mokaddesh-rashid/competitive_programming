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
typedef pair<int,int> pr;


//set<int>::iterator ii;


LL ar[1001], br[1001], n ,m, up ,low;
int dp[10000010][5];

LL rec( int x, int y , int z )
{
    //cout << x << ' ' << y << ' ' << z << endl;
    LL temp = 0;
    if( y == 4 && ( low <= z && z <= up ) ) return 1;
    if( x == n || y == 4 || z > up ) return 0;
    if( dp[z][y] != -1 ) return dp[z][y];
    else return dp[z][y] = rec( x, y+1, z+ar[x] ) + rec( x+1, y, z );

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;


    while(t--)
    {
        memset( dp, -1, sizeof( dp ) );
        //memset( dp, -1, sizeof(dp) );
        LL i, j, x = 0, y, k;

        cin >> n;

        for( i=0; i<n; i++ )
            cin >> ar[i];

        sort( ar, ar+n, greater<int>() );

        cin >> low >> up;

        cout << "Case " << ca++ << ": ";
        cout << rec( 0, 0, 0 ) << endl;

    }

    return 0;

}




