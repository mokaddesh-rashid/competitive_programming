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

int n, dp[200001][10][10], k, s;

int rec( int x, int y , int z )
{
    cout << x << ' ' << y << ' ' << z << endl;
    int temp = 0, i;
    if( x == n ) return 1;

    if( i < s )
    {
        for( i=0; i<k; i++ )
        {
            if( i != y && i != z ) temp += temp, rec( x+1, i, y );
            //cout << endl;
        }
    }
    else
    {
        for( i=0; i<k; i++ )
        {
            if( i != y )temp += rec( x+1, i, y ) ;
            //cout << endl;
        }
    }
    return temp;

}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, m;

    cin >> n >> k ;
    s = n-1;
    n = n*n;
    cout << rec( 0, -1, -1 );


    return 0;

}


