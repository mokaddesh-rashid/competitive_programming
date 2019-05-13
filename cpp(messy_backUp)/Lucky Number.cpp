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
#define MAX 1429445
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


struct Node{
    int sum;
    Node()
    {
        sum = 0;
    }
};

Node tree[4*MAX];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        if( b % 2 != 0 )
           cnd.sum = 1;
        else
            cnd.sum = 0;
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum = tree[lnd].sum + tree[rnd].sum ;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, LL v)
{
   cnd.sum = v;

}

LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}


int query2(int idx, int b, int e, int v )
{
    //cout << cnd.sum << ' ' << idx << ' ' << b << ' ' << e << ' ' << v << endl;
    if( b == e )
        return b;
    else if( cnd.sum < v )
        return -1;
    else if( tree[lnd].sum >= v )
        return query2( lnd, b, (b+e)/2, v );
    else
        return query2( rnd, ((b+e)/2)+1, e, v-tree[lnd].sum );

}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;

}


int main()
{
//    inf;
//    outf;
      int t, ca = 1;
      int  i, q, x, st, en, mid, ans, k, j, n;

      init( 1, 1, 1429441 );

      for( i=3; i<1429441; i+=2 )
      {

             k = query( 1, 1, 1429441, i, i );
             if( k == 1 )
             {
                 j = i;
                 st = 0;
                 while( j < 1429441 )
                 {
                     x = query2( 1, 1, 1429441, j-st );
                     if( x != -1 )
                        update( 1, 1, 1429441, x, x, 0 );
                     else
                        break;
                     j += i;
                     st++;
                 }
             }

      }
//      for( i=1; i<1429441; i++ )
//      {
//
//             k = query( 1, 1, 1429441, i, i );
//             if( i < 40 )
//             cout << i << ' ' << k << endl;
//
//      }

      sf(t);

      while( t-- )
      {

          sf( n );
          pf("Case %d: ", ca++ );
          pf("%d\n", query2( 1, 1, 1429441, n ) );


      }


}

