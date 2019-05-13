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
#define sf(n)       scanf(" %lld", &n)
#define sff(a,b)    scanf(" %lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<LL>::iterator ii;

LL arr[1000000];
struct info
{
   LL sum, prop;
} node[3*1000000];

void init(LL x, LL i, LL j )
{
    if( i == j )
       {
           node[x].sum = arr[j];
           return;
       }

    LL lef = x * 2;
    LL rig = x * 2 + 1;
    LL mid = ( i + j ) / 2;
    init( lef, i, mid );
    init( rig, mid+1, j );

    node[x].sum = node[lef].sum + node[rig].sum;

}

void update(LL x, LL i, LL j, LL val,LL st, LL en )
{
    if( i > en || j < st )
        return ;
    if( i >= st && j <= en )
       {
          node[x].sum += ( ( j - i + 1 ) * val );
          node[x].prop += val;
          return ;
       }

    LL lef = x * 2;
    LL rig = x * 2 + 1;
    LL mid = ( i + j ) / 2;
    update( lef, i, mid, val, st, en );
    update( rig, mid+1, j, val, st, en );

    node[x].sum = node[lef].sum + node[rig].sum ; // + ( ( j - i + 1 ) * node[x].prop );

}
LL query(LL x, LL i, LL j, LL st, LL en, LL carry )
{
    if( i > en || j < st )
        return 0;
    if( i >= st && j <= en )
       return node[x].sum + ( ( j - i + 1 ) * carry );

    LL lef = x * 2;
    LL rig = x * 2 + 1;
    LL mid = ( i + j ) / 2;
    return query( lef, i, mid, st, en, carry + node[x].prop ) + query( rig, mid+1, j, st, en,  carry + node[x].prop );

}



int main()
{
   // ios::sync_with_stdio(false);

    //inf;
    //outf;
   LL t, ca = 1;

   //cin >> t;
   sf( t );


   while( t-- )
   {
        memset( node, 0, sizeof( node ) );
        LL n, m, x, y, v, a, b, c, d;
        sff( n, m );
        pf( "Case %lld:\n", ca++ );
        //cout << n << ' ' <<  m << endl;

    while( m-- )
    {
        sf( a );
        //cin >> a;

        if( a == 0 )
        {
            //cin >> x >> y >> v;
            sff( x , y );
            x++;
            y++;
            sf( v );
            update( 1, 1, n, v, x, y );
        }
        else
        {
            sff( x, y );
            //cin >> x >> y;
            x++;
            y++;
            b = query( 1, 1, n, x, y, 0 );
            pf( "%lld\n", b ) ;
        }
    }


   }

    return 0;

}
