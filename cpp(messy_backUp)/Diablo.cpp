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
#define MAX 150005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


int n;
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
        if( b <= n )
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

int arr[150050];

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
          int  i, q, x, st, en, mid, ans, k;

          sff( n, q );
          //cin >> n >> q;

          for( i=1; i<=n; i++ )
            sf( arr[i] );
            //cin >> arr[i];
            init( 1, 1, 150001 );
          for( i=0; i<q; i++ )
          {
              char ch;
              scanf(" %c ", &ch);
              //cin >> ch;
              sf( x );
             // cin >> x;
              //cout << x << endl;
              if( ch == 'c' )
              {
                  st = 0;
                  en = 150001;
                  ans = 150001;

                  while( st <= en )
                  {
                      mid = ( st + en ) / 2;
                      k = query( 1, 1, 150001, 1, mid );

                      if( k < x )
                      {
                          st = mid + 1;
                      }
                      else
                      {
                          if( k == x )
                            ans = min( ans, mid );
                          en = mid - 1;
                      }
                  }
                 if( ans <= n )
                    pf("%d\n", arr[ans] );
                    //cout << arr[ans] << endl;
                 else
                    pf( "none\n" );
                    //cout <<  << endl;

                  update( 1, 1, 150001, ans, ans, 0 );
              }
              else
              {
                  arr[n+1] = x;
                  update( 1, 1, 150001, n+1, n+1, 1 );
                  n++;
              }
          }
      }
}

