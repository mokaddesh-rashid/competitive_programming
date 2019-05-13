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
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL ar[100010];

int main()
{
    ios::sync_with_stdio(false);

    inf;
    //outf;

    int t;

    cin >> t;

    while(t--)
    {
        LL i, j, x, y, n, m, a, b, c, d = maxx, mn = maxx;

        cin >> n;

        for( i=0; i<n; i++ )
            cin >> ar[i], mn = min( ar[i], mn );

        b = 0;
        for( i=0; i<n-1; i++ )
        {
            x = max( ar[i]-ar[i+1], ar[i+1]-ar[i] );
            if( i == 0 )
                a = x;
            else if( a != x )
               {
                  b++, c = ar[i+1], i++;
                  x = max( ar[i-1]-ar[i+1], ar[i+1]-ar[i-1] );
                  if( i+1 < n && a != x )
                        b++;
               }

        }
        if( b == 0 ) d = min( ar[0], ar[n-1] );
        if( b == 1 ) d = min( d, c ), cout << c << endl;;
            //

        b = 0;
        a = max( ar[0]-ar[2], ar[2]-ar[0] );
        for( i=2; i<n-1; i++ )
        {
            x = max( ar[i]-ar[i+1], ar[i+1]-ar[i] );
            if( a != x )
                b++;

        }
        if( b == 0 ) d = min( d, ar[1] ), cout << ar[1] << endl;;
            //cout << ar[1] << endl;

        b = 0;
        a = max( ar[1]-ar[2], ar[2]-ar[1] );
        for( i=2; i<n-1; i++ )
        {
            x = max( ar[i]-ar[i+1], ar[i+1]-ar[i] );
            if( a != x )
                b++, c = ar[i+1], i++;

        }
        if( b == 0 ) d = min( d, c ), cout << ar[0] << endl;;
            //cout << ar[0] << endl;



       if( n <= 3 ) cout << mn << endl;
       else if( d == maxx ) cout << -1 << endl;
       else cout << d << endl;
    }



    return 0;

}


