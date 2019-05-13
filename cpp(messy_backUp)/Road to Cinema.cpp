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
#define PB push_back
#define F first
#define S second
typedef pair<LL,LL> pr;

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

class compare
{
    public:
    bool operator()( pr x, pr y )
    {
        if( x.F == y.F ) return x.S < y.S;
        else return x.F < y.F;
    }
};

LL sta[1000010];
pr ar[1000010];
LL n, k, s, t;

LL chk( LL p )
{
   LL i, j, a = 0, b = 0, c = p, d, x, y, z;

   for( i=0; i<=k; i++ )
   {
       if( i == 0 ) x = sta[i];
       else x = sta[i]-sta[i-1];

       if( x <= p/2 ) a += x;
       else if( x <= p )
       {
           z = (2*x);
           y = p-x;
           z = z-y;
           a += z;
       }
       else b = 1;
   }
   // cout << p << ' ' << a << endl;
   if( a <= t && b == 0 ) return 1;

   return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, m, st, en, mid, c = maxx;

    cin >> n >> k >> s >> t;


    for( i=0; i<n; i++ )
    {
        cin >> ar[i].F >> ar[i].S;
    }

    sort( ar, ar+n, compare() );


    for( i=0; i<k; i++ )
    {
      cin >> sta[i];
    }
    sta[k] = s;
    sort( sta, sta+k+1 );

    //for( i=0; i<n; i++ )
        //cout << ar[i].F << ' ' << ar[i].S << endl;
    st = 0; en = maxx;

    while( st <= en )
    {
        mid = (st+en)/2;
        x = chk( mid );

        if( x == 1 )c = min( mid, c ), en = mid-1;
        else st = mid+1;

    }

    LL ans = maxx;
    for( i=0; i<n; i++ )
    {
        if( ar[i].S >= c ) ans = min( ans, ar[i].F );
    }

    if( ans == maxx ) cout << -1 << endl;
    else cout << ans << endl;

    return 0;

}
/*
2 1 1000000000 2000000000
111 1000000000
101 1000000000
5
*/


