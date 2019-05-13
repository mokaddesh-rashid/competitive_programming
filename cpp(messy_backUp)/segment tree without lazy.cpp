#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

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
    cnd.sum =  tree[lnd].sum + tree[rnd].sum ;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

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

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int main()
{
    LL t, ca = 1;
    sf(t);
    while(t--)
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
            pf( "%lld\n", query( 1, 1, n, x, y ) );
//        cout << query( 1, 1, n, x, y ) << endl;
        }
    }
    return 0;
}
