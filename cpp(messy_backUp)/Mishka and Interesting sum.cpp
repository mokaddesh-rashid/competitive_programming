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
   LL sum, val, lazy, maxx;

}tree[4*MAX];
LL arr[100010];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.sum = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum =  (tree[lnd].sum | tree[rnd].sum) ;

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}


LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft | rgt);
}


int main()
{
    LL t, ca = 1;

    //sf( t );

    //while( t-- )
    //{
        //pf( "Case %lld:\n", ca++ );
        memset(tree, 0, sizeof( tree ) );
        LL n, m, i, x, y;

        cin >> n ;
        //sff( n, m );

        for( LL i=1; i<=n; i++ )
            cin >> arr[i];//sf(arr[i]);

        init( 1, 1, n);
        cin >> m;
        for( i=0; i<m; i++ )
        {
            cin >> x >> y;

            cout << query( 1, 1, n, x, y ) << endl;

//        cout << query( 1, 1, n, x, y ) << endl;
        //
        }
    return 0;
}


