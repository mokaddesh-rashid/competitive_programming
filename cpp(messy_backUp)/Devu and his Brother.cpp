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
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL ar[100010], br[100010], n, m;

LL chk( LL x )
{
    LL c = 0, i, j, a, b;

    for( i=0; i<n; i++ )
    {
        if( ar[i] < x )
            c += ( x-ar[i] );
        if( br[i] > x )
            c += ( br[i]-x );
    }
    for( i=n; i<m; i++ )
    {
        if( br[i] > x )
            c += ( br[i]-x );
    }

    return c;
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, mn = maxx, z, a, b, c, mid, st, en;

    cin >> n >> m;

    for( i=0; i<n; i++ )
        cin >> ar[i];
    for( i=0; i<m; i++ )
        cin >> br[i];


   st = 0;
   en = 10000000000000;

   while( st <= en )
   {
      mid = (st+en)/2;
      a = chk(mid);
      b = chk(mid+1);
      mn = min( mn, a );
      mn = min( mn, b );
      if( a<b )
          en = mid-1;
      else
          st = mid+1;

   }


   cout << mn << endl;
    return 0;

}

