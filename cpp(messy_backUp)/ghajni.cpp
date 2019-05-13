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
   LL maxx, lazy, minn;

}tree[4*MAX];
LL arr[100010];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.maxx = arr[b];
        cnd.minn = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.maxx = max( tree[lnd].maxx , tree[rnd].maxx );
    cnd.minn = min( tree[lnd].minn , tree[rnd].minn );
    //cout << cnd.maxx << ' ' << b <<  ' ' << e << endl;
}

void update_node(LL idx, LL b, LL e, LL v)
{
    cnd.maxx = arr[b];
    cnd.lazy += v;
}


LL query_max(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.maxx;

    LL lft = query_max(lnd, b, (b+e)/2, st, en);
    LL rgt = query_max(rnd, ((b+e)/2)+1, e, st, en);
    return max( lft , rgt );
}
LL query_min(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return mx;
    if(st <= b && en >= e)
        return cnd.minn;

    LL lft = query_min(lnd, b, (b+e)/2, st, en);
    LL rgt = query_min(rnd, ((b+e)/2)+1, e, st, en);
    return min( lft , rgt );
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
//    inf;
//    outf;
    LL t, ca = 1;

    sf( t );

    while( t-- )
    {
        pf( "Case %lld: ", ca++ );
        memset(tree, 0, sizeof( tree ) );
        LL n, m, i, x = 1, y, a, b, maxx = 0;

    //cin >> n >> m;
        sff( n, m );

        for( LL i=1; i<=n; i++ )
            sf(arr[i]);

        init( 1, 1, n);

        while( x+m-1 <= n )
        {
            a = query_max( 1, 1, n, x, x+m-1 );
            b = query_min( 1, 1, n, x, x+m-1 );
            //cout << x << ' ' << x+m << ' ' << a << ' ' << b << endl;
            maxx = max( a-b, maxx );
            x++;
        }
         pf( "%lld\n", maxx );

    }
    return 0;
}



