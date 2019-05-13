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
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define LL long long
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

struct info
{
   LL maxx, lazy;

}tree[4*MAX];
LL arr[100010];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.maxx = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.maxx =  tree[lnd].maxx + tree[rnd].maxx ;
    //cout << cnd.maxx << ' ' << b <<  ' ' << e << endl;
}

void update_node(LL idx, LL b, LL e, LL v)
{
    cnd.maxx = arr[b];
    cnd.lazy += v;
}


LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 100000000;
    if(st <= b && en >= e)
        return cnd.maxx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return lft + rgt;
}

void update(LL idx, LL b, LL e, LL st, LL en, LL v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }
    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.maxx = tree[lnd].maxx + tree[rnd].maxx;
}

int main()
{
    LL t, ca = 1;

    sf( t );

    while( t-- )
    {
        pf( "Case %lld:\n", ca++ );
        memset(tree, 0, sizeof( tree ) );
        LL n, m, i, x, y;

    //cin >> n >> m;
        sff( n, m );

        for( LL i=1; i<=n; i++ )
            sf(arr[i]);

        init( 1, 1, n);

        for( i=0; i<m; i++ )
        {
            LL z;
            sf( z );

            if( z == 1 )
            {
                sf( x );
                x++;
                pf( "%lld\n",arr[x] );
                arr[x] = 0;
                update( 1, 1, n, x, x, 0 );
            }
            else if( z == 2 )
            {
                sff( x, y );
                x++;
                arr[x] += y;
                update( 1, 1, n, x, x, y );
            }
            else
            {
                sff( x, y );
                x++;
                y++;
                pf( "%lld\n", query( 1, 1, n, x, y ) );
            }
//        cout << query( 1, 1, n, x, y ) << endl;
        }

    }
    return 0;
}

