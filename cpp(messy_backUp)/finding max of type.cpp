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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
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
   int s[13];

}tree[4*MAX];
int arr[100010];

void init(int idx, int b, int e )
{

    if( b == e )
    {
        int x = arr[b];
        cnd.s[x] = 1;
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    for( int i=1; i<=10; i++ )
        cnd.s[i] = tree[lnd].s[i] + tree[rnd].s[i];

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, int v)
{
    for(int i=1; i<=10; i++ )
            cnd.s[i] = 0;
        cnd.s[v] = 1;
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
    for(int i=1; i<=10; i++ )
        cnd.s[i] = tree[lnd].s[i] + tree[rnd].s[i];
}


int query(int idx, int b, int e, int st, int en, int t )
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.s[t];

    int lft = query(lnd, b, (b+e)/2, st, en, t);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en, t);
    return lft + rgt;
}



int main()
{
    int t, ca = 1;

    sf( t );

    while( t-- )
    {
        pf( "Case %d:\n", ca++ );
        memset(tree, 0, sizeof( tree ) );
        int n, m, i, x, y, z;

    //cin >> n >> m;
        sff( n, m );

        for( int i=1; i<=n; i++ )
            sf(arr[i]);

        init( 1, 1, n);

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z;

            pf( "%d\n", query( 1, 1, n, x, y, z ) );

            cin >> x >> y;

            update( 1, 1, n, x, x, y );

//        cout << query( 1, 1, n, x, y ) << endl;
        }

    }

    return 0;
}



