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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

LL ci[100010], p[100010], n, m;

LL chk( LL v )
{
    LL i = 0, j = 0, a = 0, d;

    while( j < m && i < n )
    {
        d = max( ci[i]-p[j], p[j]-ci[i] );

        if( d <= v )
        {
            a++;
            i++;
        }
        else
            j++;
    }

    if( a == n )
        return 1;

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = maxx, y, st = 0, mid, en = maxx;

    cin >> n >> m ;

    for( i=0; i<n; i++ )
        cin >> ci[i];
    for( i=0; i<m; i++ )
        cin >> p[i];

    while( st <= en )
    {
        mid = (st+en)/2;
        y = chk(mid);
        //cout << mid << ' ' << y << endl;
        if( y == 1 )
        {
         en = mid-1;
         x = min( x, mid );
        }
        else
            st = mid+1;
    }

    cout << x;

    return 0;

}


