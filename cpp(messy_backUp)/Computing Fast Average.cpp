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
#define stf(n)       scanf("%s", n)
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

struct Node{
    LL lazy, sum, tm;
    Node()
    {
        tm = lazy = sum = 0;
    }
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum = ((e-b+1) * v);
    cnd.lazy = v;
    cnd.tm = 1;
}

void lazy_update(int idx, int b, int e)
{
    if( cnd.tm != 0 )
    {
        update_node(lnd, b, (b+e)/2, cnd.lazy);
        update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    }
    cnd.lazy = 0;
    cnd.tm = 0;
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
}

void init(int idx, int b, int e )
{

    if( b == e)
    {
        cnd.sum = 1;
        return ;
    }

    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int main()
{

    LL t, ca = 1;

    //cin >> t;
    sf(t);

    while( t-- )
    {
        memset( tree, 0, sizeof(tree) );
        pf( "Case %lld:\n", ca++ );
        LL n, m, i, j, x, y, z, v, a, b, c;

        sff( n, m );
    //cin >> n >> m;

    for( i=0; i<m; i++ )
    {
        //cin >> z;
        sf( z );
        if( z == 1 )
        {
            sf( x );
            sff( y, v );
            //cin >> x >> y >> v;
            update( 1, 1, n, x+1, y+1, v );
        }
        else
        {
            sff( x, y );
            //cin >> x >> y;
            a = query( 1, 1, n, x+1, y+1 ) ;
            b = y - x + 1;
            c = __gcd( a, b );
            //cout << a << ' ' << b << endl;
            a /= c;
            b /= c;
            //cout << a << ' ' << b << endl;
            if( b != 1 )
                pf("%lld/%lld\n", a, b );
                //cout << a << '/' << b << endl;
            else
                pf( "%lld\n",a );
                //cout << a << endl;



        }
    }

    }
}
