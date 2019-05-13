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
   LL f, s, p;

}tree[4*MAX];
LL arr[100010], brr[100010];

info nl;

void init(LL idx, LL b, LL e )
{
    int v;

    if( b == e )
    {
        cnd.f = arr[b];
        cnd.s = brr[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    v = min( tree[lnd].f , tree[rnd].s );
    cnd.p =  tree[lnd].p + tree[rnd].p + v;
    cnd.f =  tree[lnd].f + tree[rnd].f - v;
    cnd.s =  tree[lnd].s + tree[rnd].s - v;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}


info queryf(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return nl;
    if(st <= b && en >= e)
        return cnd;

    info lft = queryf(lnd, b, (b+e)/2, st, en);
    info rgt = queryf(rnd, ((b+e)/2)+1, e, st, en);
    info ret;

    int v = min( lft.f , rgt.s );
    ret.p = lft.p + rgt.p + v;
    ret.f = lft.f + rgt.f - v;
    ret.s = lft.s + rgt.s - v;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    string str;
    int n, x = 0, y = 0 ,i, j, a, b, c, m;

    cin >> str;
    n = str.size();

    for( i=0; i<n; i++ )
    {
        if( str[i] == '(' )
            {
                arr[i+1] = 1;
                x++;
            }
        else if( y < x )
            {
                brr[i+1] = 1;
                y++;
            }
    }
    init( 1, 1, n);
    cin >> m;
    for( i=0; i<m; i++ )
    {
        cin >> x >> y;

        info ans = queryf( 1, 1, n, x, y );
        cout << ans.p*2 << endl;
//        cout << query( 1, 1, n, x, y ) << endl;
    }

    return 0;
}



