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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int pa[1000010], ar[1000010], cn[1000010];
int br[1000010];

int fi_pa( int x )
{
    if( pa[x] == x )
        return x;
    else
       {
          pa[x] = fi_pa( pa[x] );
          return pa[x];
       }
}

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b;

    //cin >> n >> m;
    sff( n, m );

    for( i=1; i<=n; i++ )
    {
        pa[i] = i;
    }
    for( i=1; i<=n; i++ )
        sf( ar[i] );
        //cin >> ar[i];

    for( i=0; i<m; i++ )
    {
        sff( a, b );
        //cin >> a >> b;
        x = fi_pa(a);
        y = fi_pa(b);
        if( x != y )
        {
            pa[y] = x;
        }
        //x = fi_pa(a);
        //y = fi_pa(b);
    }

    for( i=1; i<=n; i++ )
    {
        if( pa[i] == i && cn[pa[i]] == 0 )
        {
            //cout << 'h' << endl;
            x = 0;
            for( j=1; j<=n; j++ )
            {
                if( pa[j] == i || pa[pa[j]] == i )
                {
                    br[x] = ar[j];
                    x++;
                }
            }
            y = 0;
            sort( br, br+x, greater <int>() );
             for( j=1; j<=n; j++ )
            {
                if( pa[j] == i )
                {
                    ar[j] = br[y];
                    y++;
                }
            }
            cn[pa[i]]++;
        }
    }

     for( i=1; i<=n; i++ )
        pf("%d ", ar[i] );
        //cout << ar[i] << ' ';
    return 0;

}


