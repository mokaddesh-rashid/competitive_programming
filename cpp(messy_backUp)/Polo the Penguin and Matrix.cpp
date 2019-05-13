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
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL ar[100010], n, d, ck;

LL chk( LL x )
{
    LL c = 0, a, b,  y, z;
    y = z = a = b = 0;
    for(int i=0; i<n; i++ )
    {
       a = max( ar[i]-x , x-ar[i] );
       b = a/d;
       if( a%d )
        ck = 1;
       c += b;
    }

    return c;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, m, a, b, c = maxx, en, st, mid;

    cin >> a >> b >> d;

    n = a*b;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
    }

    m = ar[0]%d;
    en = 10000;
    st = 0;

    while( st <= en )
    {
        mid = (st+en)/2;

        a = chk( mid*d+m );
        b = chk( mid*d+m+d );
        c = min( c, a );
        c = min( c, b );

        if( a > b )
        {
            st = mid+1;
        }
        else
            en = mid-1;
    }

    if( ck == 0 )
        cout << c;
    else
        cout << -1;

    return 0;

}


