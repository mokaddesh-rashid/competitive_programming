#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

struct node
{
    LL x, y, p;

}ar[100010];
class compare
{
    public:
        bool operator()( node x, node y )
        {
            if( x.x < y.x ) return true;
            else if( x.x == y.x && x.y > y.y ) return true;
            else return false;
        }
};

struct info
{
   LL sum, l, r, x, y;

}tree[4*MAX];

void init(LL idx, LL b, LL e )
{
    LL ex = 0;

    if( b == e )
    {
        cnd.l = ar[b-1].x;
        cnd.r = ar[b-1].y;
        cnd.sum = ar[b-1].y - ar[b-1].x + 1;
        //cout << idx << ' ' << cnd.l << ' ' << cnd.r << ' ' << cnd.sum << endl;
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);

    if( tree[lnd].r >= tree[rnd].l )
    {
        if( tree[lnd].r >= tree[rnd].r )
        {
            cnd.l = tree[lnd].l;
            cnd.r = tree[lnd].r;
            ex = tree[rnd].sum;
        }
        else
        {
            //cout << 'k' << ' ';
            cnd.l = tree[lnd].l;
            cnd.r = tree[rnd].r;
            ex = tree[lnd].r - tree[rnd].l +1;
        }
    }
    else if( idx % 2 == 0 )
    {
        cnd.l = tree[rnd].l;
        cnd.r = tree[rnd].r;
    }
    else
    {
       cnd.l = tree[lnd].l;
       cnd.r = tree[lnd].r;
    }
    cnd.sum =  tree[lnd].sum + tree[rnd].sum - ex;
     //cout << idx << ' ' << cnd.l << ' ' << cnd.r << ' ' << cnd.sum << ' ' << ex << endl;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(LL idx, LL b, LL e, LL v)
{
    if( v == 0 )
    {
        cnd.l = 0;
        cnd.r = 0;
        cnd.sum = 0;
    }
    else
    {
        cnd.l = ar[b-1].x;
        cnd.r = ar[b-1].y;
        cnd.sum = ar[b-1].y - ar[b-1].x + 1;
    }
}


void update(LL idx, LL b, LL e, LL st, LL en, LL v)
{
    LL ex = 0;
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
        return update_node( idx, b , e, v );

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);

    if( tree[lnd].r >= tree[rnd].l )
    {
        if( tree[lnd].r >= tree[rnd].r )
        {
            cnd.l = tree[lnd].l;
            cnd.r = tree[lnd].r;
            ex = tree[rnd].sum;
        }
        else
        {
            //cout << 'k' << ' ';
            cnd.l = tree[lnd].l;
            cnd.r = tree[rnd].r;
            ex = tree[lnd].r - tree[rnd].l +1;
        }
    }
    else if( idx % 2 == 0 )
    {
        cnd.l = tree[rnd].l;
        cnd.r = tree[rnd].r;
    }
    else
    {
       cnd.l = tree[lnd].l;
       cnd.r = tree[lnd].r;
    }
    cnd.sum =  tree[lnd].sum + tree[rnd].sum - ex;

    if( tree[lnd].sum == 0 )
    {
        cnd.l = tree[rnd].l;
        cnd.r = tree[rnd].r;
        cnd.sum = tree[rnd].sum;
    }


    if( tree[rnd].sum == 0 )
    {
        cnd.l = tree[lnd].l;
        cnd.r = tree[lnd].r;
        cnd.sum = tree[lnd].sum;
    }

}

int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        cout << "Case #" << ca++ << ": " ;
        memset( tree, 0, sizeof( tree) );
        memset( ar, 0, sizeof (ar) );
        LL i, j, x, y, n, m, l, k, a, b, c1, c2, d, r, ans = maxx;

        cin >> n >> l >> r >> a >> b >> c1 >> c2 >> m;

        for( i=0; i<n; i++ )
            {
                if( i == 0 )
                {
                   ar[i].x = l;
                   ar[i].y = r;
                }
                else
                {
                    x = ( a*l + b*r + c1 ) % m;
                    /// xi = ( A*xi-1 + B*yi-1 + C1 ) modulo M
                    y = ( a*r + b*l + c2 ) % m;
                    ///yi = ( A*yi-1 + B*xi-1 + C2 ) modulo M.
                    ar[i].x = min( x, y );
                    ar[i].y = max( x, y );
                    //cout << x  << ' ' << y << endl;
                    l = x;
                    r = y;
                }
            }

        sort( ar, ar+n, compare() );



        init( 1, 1, n );

        for( i=0; i<n; i++ )
       {
         update( 1, 1, n, i+1, i+1, 0 );
         //cout << tree[1].sum << endl;
         ans = min( ans, tree[1].sum );
         update( 1, 1, n, i+1, i+1, 1 );
       }

        cout << ans;

    }

    return 0;

}


