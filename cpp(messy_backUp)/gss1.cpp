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
   LL sum, maxx, lef_sum, rig_sum;

}tree[4*MAX];

LL arr[100010];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.maxx = cnd.lef_sum = cnd.rig_sum = cnd.sum = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);

    cnd.sum =  tree[lnd].sum + tree[rnd].sum ;

    cnd.lef_sum = max( tree[lnd].lef_sum, tree[lnd].sum );
    cnd.lef_sum = max( cnd.lef_sum, tree[lnd].sum + tree[rnd].lef_sum );
    cnd.lef_sum = max( cnd.lef_sum, cnd.sum );


    cnd.rig_sum = max( tree[rnd].rig_sum, tree[rnd].sum );
    cnd.rig_sum = max( cnd.rig_sum, tree[rnd].sum + tree[lnd].rig_sum );
    cnd.rig_sum = max( cnd.rig_sum, cnd.sum );

    cnd.maxx = max( cnd.sum, cnd.lef_sum );
    cnd.maxx = max( cnd.maxx, cnd.rig_sum );

}


LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return idx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if( rgt - lft == 1 )
    {
        LL ans;

        ans = max( tree[lft].sum + tree[rgt].sum , tree[lft].maxx );
        ans = max( ans, tree[rgt].maxx );

        if( ans == tree[lft].sum + tree[rgt].sum )
            return idx;
        else if ( ans == tree[lft].maxx )
            return lft;
        else
            return rgt;
    }
    else
    {
        if( tree[lft].maxx > tree[rgt].maxx )
            return lft;
        else
            return rgt;
    }

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
            cin >> x >> y;
                x = query( 1, 1, n, x, y );
                pf( "%lld\n", tree[x].maxx );

//        cout << query( 1, 1, n, x, y ) << endl;
        }

    }
    return 0;
}



