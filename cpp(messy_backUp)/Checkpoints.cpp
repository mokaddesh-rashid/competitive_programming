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


int ar[2000010], sa[2000010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b, c, d = maxx, p ;

    cin >> n >> a ;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
    }

    sort( ar, ar+n );

    if( n == 1 )
    {
        cout << 0;
        return 0;
    }

    p = upper_bound( ar, ar+n, a ) - ar;

    x = max( ar[n-1] - a, a-ar[n-1] );
    y = ar[n-1] - ar[1];
    d = min( d, x+y );

    x = max( ar[n-2] - a, a-ar[n-2] );
    y = ar[n-2] - ar[0];
    d = min( d, x+y );



    x = max( ar[0] - a, a-ar[0] );
    y = ar[n-2] - ar[0];
    d = min( d, x+y );

    x = max( ar[1] - a, a-ar[1] );
    y = ar[n-1] - ar[1];
    d = min( d, x+y );

    cout << d << endl;






    return 0;

}
