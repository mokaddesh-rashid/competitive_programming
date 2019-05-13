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

LL ar[1000010], n, m , t, nd[1000010];

int chk( LL l )
{
    LL c = 0, k = t, a, x = 0;

    for( int i=0; i<n; i++ )
    {
        x += nd[i];
        a = l-ar[i]-x;
        //cout << x << ' ' << ar[i] << ' ' << endl;
        if( a > 0 )
        {
            c += a;
            x += a;
            nd[i+t] = a*-1;
        }

        nd[i] = 0;
    }

    if( c > m )
        return 0;

    return 1;
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y = 0, st, en , mid;

    cin >> n >> m >> t;

    for( i=0; i<n; i++ )
        cin >> ar[i];

    //t = m*t;

    st = 0;
    en = 1000000009+m;

    while( st <= en )
    {
        mid = (st+en)/2;

        x = chk( mid );

        if( x == 1 )
        {
            st = mid+1;
            y = max( y, mid );
        }
        else
            en = mid-1;
    }


    cout << y;

    return 0;

}


