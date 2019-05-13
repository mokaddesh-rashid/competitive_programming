#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define stf(n)       scanf("%s", n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define LL long long
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

struct Node{
    LL lazy, sum, tm, ze, on;
    Node()
    {
        tm = lazy = sum = 0;
    }
};

Node tree[4*MAX];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.sum = 1;
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum = tree[lnd].sum + tree[rnd].sum ;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, LL v)
{
    int x = v, y, z, a, c, d;
    x %= 3;
    a = cnd.sum;
    c = cnd.ze;
    d = cnd.on;
    if( x == 1 )
    {
      cnd.ze = a;
      cnd.on = c;
      cnd.sum = d;
    }
    else if( x == 2 )
    {
      cnd.ze = d;
      cnd.on = a;
      cnd.sum = c;
    }
    cnd.tm = 1;
    cnd.lazy += v;

}

void lazy_update(int idx, int b, int e)
{
    if( cnd.tm != 0 )
    {
        update_node(lnd, b, (b+e)/2, cnd.lazy);
        update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    }
    cnd.tm = 0;
    cnd.lazy = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    lazy_update(idx, b, e);
    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
    cnd.ze = tree[lnd].ze+tree[rnd].ze;
    cnd.on = tree[lnd].on+tree[rnd].on;


}


int main()
{
//    inf;
//    outf;
  int t, ca = 1;

  sf(t);

  while( t-- )
  {
       pf("Case %d:\n", ca++ );
   memset( tree, 0, sizeof(tree) );
   int n, m, i, x, y, z, a;
   sff( n, m );
   //cin >> n >> m;

   init( 1, 1, n );

   for(i=0; i<m; i++ )
   {
       sf( x );
       sff( y, z );
      //cin >> x >> y >> z;
      y++;
      z++;

      if( x == 0 )
      {
          update( 1, 1, n, y, z, 1 );
      }
      else
      {
          a = query( 1, 1, n, y, z );
          pf("%d\n",a);
      }
   }

  }


}


