#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           int
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;



LL pri[1000050], ar[1000010], sg[100010], pa[100010], pos[100010], val[100010];

void sieve( LL n )
{
    LL m = sqrt(n), i, j;
    for( i=2; i<=m; i ++)
        if( pri[i] == 0 )
            for( j=i*i ; j<=n; j += i )
                if( pri[j] == 0)
                      pri[j] = i ;

    for( i=3 ; i <= n; i += 2)
        if( pri[i] == 0 )
            pri[i] = i;
    pri[1] = 1;
    pri[2] = 2;
}

int fin_pa( int p )
{
    if( pa[p] == p )
        return p;
    return pa[p] = fin_pa( pa[p] );
}

struct Node{
    LL lazy, mx, sm;
};

Node tree[4*MAX];

void init(LL idx, LL b, LL e )
{
    if( b == e )
    {
        cnd.mx = pri[ar[b-1]];
        cnd.sm = ar[b-1];
        return ;
    }

    init(lnd, b, (b+e)/2 );
    init(rnd, ((b+e)/2)+1, e );
    cnd.mx = max(tree[lnd].mx, tree[rnd].mx);
    cnd.sm = tree[lnd].sm + tree[rnd].sm;
}
LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.mx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
}
LL next(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sm;

    LL lft = next(lnd, b, (b+e)/2, st, en);
    LL rgt = next(rnd, ((b+e)/2)+1, e, st, en);
    return lft+rgt;

}
void update_node(LL idx, LL b, LL e, LL v)
{
    //cout << b << ' ' << pri[ar[b-1]] << endl;
    cnd.sm = ar[b-1];
    cnd.mx = pri[ar[b-1]];
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
    cnd.mx = max(tree[lnd].mx, tree[rnd].mx);
    cnd.sm = tree[lnd].sm + tree[rnd].sm;
}

int main()
{
        ios::sync_with_stdio(false);
        //inf;
        //outf;
        memset( pri, 0, sizeof(pri));/// number of prime initially 0

        sieve(1000005); /// range of the sieve

        int t;
        cin >> t;
        while(t--)
        {
        memset( ar, 0, sizeof(ar) );
        memset( tree, 0 ,sizeof(tree));

        LL i, j, a, b, c, n, x = 0, y=0, m, l, r;

        cin >> n >> m;

        for( i=0; i<=n+1; i++ )
            pa[i] = i;

        for( i=0; i<n; i++)
                cin >> ar[i];
        init( 1, 1, n );
        while(m--)
        {
                cin >> a >> l >> r;
                b = l;
                c = r;
                if( a == 0 )
                {
                   while( b <= c )
                    {
                        LL st, en, mid, k;
                        ar[b-1] /= pri[ar[b-1]];
                        update( 1, 1, n, b, b, 1 );
                        x = b;
                        while( st <= en )
                        {
                            mid = (st+en)/2;
                            k = next( 1, 1, n, b, mid );
                            if( k == mid-b+1 )
                                st = mid+1, x = max( x, mid);
                            else
                                st = en-1;
                        }
                        if( ar[b-1] == 1 )
                            pa[b] = x ;

                        b = max( x, b+1);

                    }

                }
                else
                {
                     cout << query( 1, 1, n, l, r ) << endl;
                }
                //cout << endl << endl;

        }

        }

}




