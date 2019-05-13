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
   int  maxx;

}tree[4*MAX];

int arr[100010];

void init(int idx, int b, int e )
{

    if( b == e )
    {
        cnd.maxx = arr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.maxx =  max (tree[lnd].maxx ,tree[rnd].maxx ) ;

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}


int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.maxx;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft , rgt);
}

int st[100010] = {0}, en[100010] = {0}, in[100010];
int main()
{
    int t, ca = 1;

    sf( t );

    while( t-- )
    {
        pf( "Case %d:\n", ca++ );
        memset(tree, 0, sizeof( tree ) );
        int z, a = 0, n, m, i, x, y, cnt = 0, b;

    //cin >> n >> m;
        sff( n, m );
        sf( m );

        for( int i=1; i<=n; i++ )
            sf( in[i] );

        for( i=1; i<=n; i++ )
        {
            if( a != in[i] )
            {
                cnt = 1;
                a = in[i];
                st[a] = i;
                en[a] = i;
            }
            else
            {
                cnt++;
                en[a] = i;
            }

            arr[i] = cnt;

        }

        init( 1, 1, n);

        //for( i=1; i<=n; i++ )
           // cout << in[i] << ' ' << arr[i] << ' ' << st[in[i]] << ' ' << en[in[i]] << endl;

        for( i=0; i<m; i++ )
        {
            //cin >> a >> b;

            sff( a, b );

            if( in[a] == in[b] )
            {
                x = b-a+1;
            }
            else
            {
                x = en[in[a]] - a + 1;
                y = b - st[in[b]] + 1;
                //cout << en[in[a]]+1 << ' ' << st[in[b]]-1 << endl;
                if( en[in[a]]+1 <= st[in[b]]-1 )
                  z = query( 1, 1, n, en[in[a]]+1, st[in[b]]-1 );
                else
                  z = 0;

                x = max( x, y );
                x = max( x, z );
            }

            pf("%d\n", x );
        }



    }
    return 0;
}



