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
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

struct info
{
   int sum;

}tree[4*MAX];

int arr[100010], n;

void init(int idx, int b, int e )
{

    if( b == e )
    {
        cnd.sum = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum =  min ( tree[lnd].sum, tree[rnd].sum ) ;

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 10000000;
    if(st <= b && en >= e)
        return cnd.sum;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return min( lft, rgt );
}

int forwardd( int x )
{
    int st = x, en = n, mid, a, b, c = x;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        a = query( 1, 1, n, x, mid );
        //cout << x << ' ' << mid << ' ' << a << ' ' << arr[x] << endl;

        if( a >= arr[x] )
        {
            c = max( c, mid );
            st = mid + 1;
        }
        else
            en = mid - 1;
    }

    //cout << c << endl << endl;

    return c;


}

int backwardd( int x )
{
    int st = 1, en = x, mid, a, b, c = x;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        a = query( 1, 1, n, mid, x );

        if( a >= arr[x] )
        {
            c = min( c, mid );
            en = mid - 1;
        }
        else
            st = mid + 1;
    }

    return c;


}


int main()
{
    int t, ca = 1;

    sf( t );

    while( t-- )
    {

        memset(tree, 0, sizeof( tree ) );
        int  m, i, x, y, z = 0;

    //cin >> n >> m;
        sf( n );

        for( int i=1; i<=n; i++ )
            sf(arr[i]);

        init( 1, 1, n);

        for( i=1; i<=n; i++ )
        {
            z = max( arr[i], z );

            if( i == 1 )
            {
               x = forwardd( i );
               z = max( z, (x-i+1)*arr[i] );
            }
            else if( i == n )
            {
                x = backwardd( i );
                z = max( z, (i-x+1)*arr[i] );
            }
            else if( arr[i] == arr[i-1] && arr[i] == arr[i+1] && arr[i] == arr[i-2] )
              continue;
            else if( arr[i+1] >= arr[i] && arr[i-1] >= arr[i] )
            {
                x = forwardd( i );
                y = backwardd( i );
                //cout << arr[i] << ' ' << x << ' ' << y <<  endl;
                z = max( z, (x-y+1)*arr[i] );
            }
            else if( arr[i] < arr[i+1] )
            {
                x = forwardd( i );
                z = max( z, (x-i+1)*arr[i] );
            }
            else if( arr[i] < arr[i-1] )
            {
                x = backwardd( i );
                z = max( z, (i-x+1)*arr[i] );
            }


        }
        pf( "Case %d: %d\n", ca++, z );
        //cout << z << endl;

    }
    return 0;
}
