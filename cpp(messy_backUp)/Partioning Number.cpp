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

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

LL dp[100010][3], n, m, p;


LL rec( int x , int z )
{
    //cout << x << endl;
    if( x == n ) return 1;
    if( x > n || z > n ) return 0;
    //if( dp[x][z] != -1 ) return dp[x][z];
    if( z == 2 ) return dp[x][z] = rec( x+p+2 , 2 );
    else if( z == 1 ) return dp[x][z] = rec( x+p+1 , 1 ) + rec( x+p+2, 2 );
    return dp[x][z] =  rec( x+p , 0 ) + rec( x+p+1 , 1 ) + rec( x+p+2, 2 );


}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        LL i, j, x = 0, y, d, b, a, c;

        cin >> n >> d ;

       LL e, f;
       for( i=d; i<=n; i += d )
       {
           a = (n/i);
           c = n%i;
           if( i != 1 ) e = n%(i-1);
           else e = n+1;
           f = n%(i+1);
           b = 1;

           //if( (n-a)%i == 0 || (n+a)%i == 0 || n%i == 0 || c-100 <= a || (i-a-100) <= a ) b = 0;
           if( c <= a+1 || e <= a+1 || f <= a+1 ) b = 0;
           if( b == 1 ) continue;

           mem( dp, -1 );
           p = i;
           x += rec( p, 0 );
          //cout << p << ' ' << rec( p, 0 ) << endl;
       }

        cout << "Case #" << ca++ << ": " << x << endl;
    }

   return 0;

}


