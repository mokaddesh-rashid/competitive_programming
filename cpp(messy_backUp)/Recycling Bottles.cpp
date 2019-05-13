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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j;
    long double x, y, n, m, x1, y1, a, b, c, d, e, ans = 0, f, d1, d2, g, h;

    cin >> x >> y >> x1 >> y1 >> d1 >> d2 ;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> a >> b;
        g = ( a - d1 ) * ( a - d1 );
        h = ( b - d2 ) * ( b - d2 );
        g = g+h;
        c = ( a - x ) * ( a - x );
        d = ( b - y ) * ( b - y );
        e = c + d;
        c = ( a - x1 ) * ( a - x1 );
        d = ( b - y1 ) * ( b - y1 );
        f = c + d;
        e = min( e+g, f+g );
        e = sqrt( e );
        ans += e;

    }

     cout << ans;



    return 0;

}


