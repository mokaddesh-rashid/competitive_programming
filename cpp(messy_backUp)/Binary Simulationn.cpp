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
#define stf(n)       scanf("%s", n)
#define sff(a,b)    scanf("%d %d", &a, &b)
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
    LL lazy, sum;
    Node()
    {
        lazy = sum = 0;
    }
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    update_node(lnd, b, (b+e)/2, cnd.lazy);
    update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    cnd.lazy = 0;
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

int main()
{

    int  t, ca = 1;

    //cin >> t;
    sf( t );

    while( t-- )
    {
        memset( tree, 0, sizeof(tree) );
        //cout << "Case " << ca++ << ":\n";
        pf( "Case %d:\n", ca++ );
        int  i, j, x, y, n, m;
        char str[1000010];
        char ch;
        stf( str );
        n = strlen( str ) + 1 ;
        //cin >> m;
        sf( m );
        while( m-- )
        {
            //cin >> ch;
            scanf( " %c", &ch ); /// age e input niye ney
            //cout << ch;
            if( ch == 'I' )
            {
                sff( x, y );
                //cin >> x >> y;
                update( 1, 1, n, x, y, 1 );
            }
            else
            {
                sf(x);
                //cin >> x;
                y = query( 1, 1, n, x, x) ;

                if( y % 2 )
                {

                    if( str[x-1] == '0' )
                        pf( "%d\n",1 );
                        //cout << 1;
                    else
                       pf( "%d\n",0 );
                        //cout << 0;
                }
                else
                {

                    if( str[x-1] != '0' )
                        pf( "%d\n",1 );
                        //cout << 1;
                    else
                        pf( "%d\n",0 );
                }
            }

        }

    }


    return 0;
}
