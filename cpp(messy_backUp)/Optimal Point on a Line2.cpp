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

LL ar[300010], lr[300010], rr[300010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL a, b, c, i, j, x = 0, y = 0, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
    }

    sort( ar, ar+n );

    for( i=0; i<n; i++ )
    {
        if( i > 0 )
        {
            a = ar[i]-ar[i-1];
            b = (i-1)*a;
            lr[i] = lr[i-1]+a+b;
        }
        //cout << ' ' << lr[i] << endl;

    }
    j = 0;
    for( i=n-1; i>=0; i--,j++ )
    {
        if( i < n-1 )
        {
            a = -ar[i]+ar[i+1];
            b = (j-1)*a;
            rr[i] = rr[i+1]+a+b;
        }
        //cout << ' ' << rr[i] << endl;

    }

    LL mn = maxx, p = 0;
    for( i=0; i<n; i++ )
    {
        a = lr[i]+rr[i];

        if( a < mn )
            p = ar[i];
        mn = min( mn, a );
    }

    cout << p << endl;

    return 0;

}


