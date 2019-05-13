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
#define mn          (long long)-1000000009
#define mx          (long long) 1000000009
#define mod          1000000009
#define LL           int
#define MAX 200005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

struct info
{
   int minn, val, lazy, maxx;

}tree[4*MAX];
int arr[200010], brr[200010];

void init(int idx, int b, int e )
{

    if( b == e )
    {
        cnd.maxx = arr[b];
        cnd.minn = brr[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.maxx =  max( tree[lnd].maxx, tree[rnd].maxx );
    cnd.minn =  min( tree[lnd].minn, tree[rnd].minn );
}

struct ret
{
    int h, l;
};
ret queryMax(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b )
    {
        ret bro;
        bro.h = mn;
        bro.l = mx;
        return bro;;
    }
    if(st <= b && en >= e)
    {
        ret bro;
        bro.h = cnd.maxx;
        bro.l = cnd.minn;
        return bro;
    }
    ret lft, rgt, bruh;
    lft = queryMax(lnd, b, (b+e)/2, st, en);
    rgt = queryMax(rnd, ((b+e)/2)+1, e, st, en);

    bruh.h = max( lft.h, rgt.h );
    bruh.l = min( lft.l, rgt.l );
    return bruh;
}

int fin( int x, int n )
{
    int st,  en, mid, i, j, a, b, c = 50, d = x, e;
    ret bruh;
    st = x;
    en = n;

    while( st <= en )
    {
        //cout9 << x << ' ' << en << ' ' << a << ' ' << b << endl;
        //cout << x << ' ' << en << endl;
        mid = (st+en)/2;
        bruh = queryMax( 1, 1, n, x, mid );
        a = bruh.h;
        b = bruh.l;
        if( a <= b )
            st = mid+1;
        else if( a > b )
            en = mid-1;
        if( a == b )
        {
            d = max( d, mid );
        }
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    int i, j , n, x, y, a, b, d, st, en, mid, e;
    long long c = 0;
    ret bruh;
    cin >> n;
    //sf(n);
    for( i=1; i<=n; i++ )
        cin >> arr[i];
    for( i=1; i<=n; i++ )//sf(brr[i]);
        cin >> brr[i];
    init( 1, 1, n );
    for(int i=1; i<=n; i++ )
        {
            x = fin( i , n );
            //cout << i << ' ' << x << endl;
            bruh = queryMax( 1, 1, n, i, x );
            a = bruh.h;
            b = bruh.l;

            if( a == b )
                {
                    d = x;
                    st = i;
                    en = x;

                    while( st <= en )
                    {
                       mid = (st+en)/2;
                       bruh = queryMax( 1, 1, n, i, mid );
                       a = bruh.h;
                       b = bruh.l;///queryMin( 1, 1, n, i, mid );
                       //cout << mid << ' ' << a <<  ' ' << b << endl;
                       if( a == b )
                       {

                           d = min( d, mid );
                           en = mid-1;
                       }
                       else
                           st = mid+1;
                    }
                   //cout << d << ' ' << x << endl << endl;
                    e = ( x-d+1 );
                    c += e;
                    //cout << e << endl;


                    j = i+1;

                    while( j <= x )
                    {
                        int q, p;
                       //cout << j << endl;
                       d = max( j, d );
                       bruh = queryMax( 1, 1, n, d, x );
                       a = bruh.h;
                       b = bruh.l;
                       bruh = queryMax( 1, 1, n, j, d );
                       q = bruh.h;
                       p = bruh.l;
                       if( a == b && q == p )
                       {
                           e = x-d+1;
                           c += e;
                       }
                       else
                         break;
                       //cout << e << endl;
                       j++;

                    }

                    i = j-1;


                }
            //else
                //cout << endl << endl;
        }
     cout << c;
    //pf("%I64d", c );
    return 0;
}
