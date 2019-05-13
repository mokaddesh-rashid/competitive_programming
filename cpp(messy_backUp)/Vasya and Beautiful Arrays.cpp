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

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;

int arr[300030], use[300030];

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( use, 0, sizeof( use ) );
    int i, j, x = 10000000, y, n, m, k, a = 1;

    //cin >> n >> k;
    sff( n, k );

    for( i=0; i<n; i++ )
       {
           // cin >> arr[i];
           sf( arr[i] );
           x = min( arr[i], x );
       }

    int     z = 2, ans = 1;

    while( x >= z )
    {
        if( use[z] == 0 )
        {
           y = 0;
           a = z;
        for( i=0; i<n; i++ )
        {
            if( arr[i] % z <= k )
                y++;
            else
                break;
        }

        if( y != n )
           {
               while( a <= x )
           {
               use[a]++;
               a += z;
           }

           }
        else
        {
            ans = max( z, ans );
        }

        }

        z++;
    }

    cout << ans;







    return 0;

}


