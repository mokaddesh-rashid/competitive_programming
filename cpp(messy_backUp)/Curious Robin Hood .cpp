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

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

LL  arr[1000000];
LL  node[3*1000000];

void init(LL  x, LL  i, LL  j )
{
    if( i == j )
       {
           node[x] = arr[j]; /// best case
           return;
       }

    LL  lef = x * 2;
    LL  rig = x * 2 + 1;
    LL  mid = ( i + j ) / 2;
    init( lef, i, mid );
    init( rig, mid+1, j );

    node[x] = node[lef] + node[rig]; /// info i have too use

}

void update(LL  x, LL  i, LL  j, LL  val,LL  ind )
{
    if( ind < i || ind > j ) /// extra segment badh diar jonno
        return;
    if( i == j )
      {
           node[x] = arr[j];
           return;
      }

    LL  lef = x * 2;
    LL  rig = x * 2 + 1;
    LL  mid = ( i + j ) / 2;
    update( lef, i, mid, val, ind );
    update( rig, mid+1, j, val, ind );

    node[x] = node[lef] + node[rig];

}
LL  query(LL  x, LL  i, LL  j, LL  st, LL  en )
{
    if( i > en || j < st ) /// extra segment badh diar jonno
        return 0;
    if( i >= st && j <= en ) /// ai segment amr drkr cz aita range maje porse
       return node[x];

    LL  lef = x * 2;
    LL  rig = x * 2 + 1;
    LL  mid = ( i + j ) / 2;
    return query( lef, i, mid, st, en ) + query( rig, mid+1, j, st, en );

}



int main()
{
    //ios::sync_with_stdio(false);

    inf;
    outf;

    LL t, ca = 1;

   // cin >> t;
    sf( t );
    while( t-- )
    {
         //cout << "Case " << ca++ << ":" << endl;
         pf( "Case %lld:\n", ca++ );
         LL  i, j, x, y, n, m, val, a, z;

   // cin >> n >> m;
        sff( n, m );

    for( i=1; i<=n; i++ )
        sf( arr[i] );
        //cin >> arr[i];

    init( 1, 1, n );

    while( m-- )
    {
        sf( x );
       //cin >> x;

       if( x == 1 )
       {
           sf ( i );
          // cin >> i;
           i++;
           pf( "%lld\n", arr[i]);
           //cout << arr[i] << endl;
           arr[i] = 0;
           update( 1, 1, n, 0, i);
       }
       else if( x == 2 )
       {
           sff( i, val );

//           cin >> i >> val;
           i++;
           arr[i] += val;
           update( 1, 1, n, val, i);
       }
       else
       {
           sff( i, j );
         // cin >> i >> j;
          i++;
          j++;
          a = query( 1, 1, n, i, j );
          pf( "%lld\n", a);
          //cout << a << endl;

       }
    }

    }

    return 0;

}



