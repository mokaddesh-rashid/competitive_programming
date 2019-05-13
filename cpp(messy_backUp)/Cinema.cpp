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
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

LL arr[200020], sub[200020], lan[200020];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = mn, y = mn, n, m, low, up, a, b, c, d, pos;

   // cin >> n ;
    sf( n );

    for( i=0; i<n; i++ )
        sf( arr[i] );
        //cin >> arr[i];

    sort( arr, arr+n );

     sf( m );
    //cin >> m;

    for( i=0; i<m; i++ )
    {
        sf( lan[i] );
        //cin >> lan[i];
    }
    for( i=0; i<m; i++ )
    {
        sf( sub[i] );
        //cin >> sub[i];
    }

    for( i=0; i<m; i++ )
    {
        a = lan[i];
        b = sub[i];

        low = lower_bound( arr, arr + n, a ) - arr;
        up =  upper_bound( arr, arr + n, a ) - arr;

        c = up - low;

        low = lower_bound( arr, arr + n, b ) - arr;
        up =  upper_bound( arr, arr + n, b ) - arr;

        d = up - low;

        if( x < c )
        {
            pos = i + 1;
            x = c;
            y = d;
        }
        else if( x == c && y < d )
        {
            pos = i + 1;
            x = c;
            y = d;
        }

    }
    pf( "%I64d", pos );
    //cout << pos;







    return 0;

}


