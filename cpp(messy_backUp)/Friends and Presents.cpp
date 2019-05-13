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


//set<int>::iterator ii;

 long long x, y, n, m, z, nn;

 int chk( long long val )
 {
     long long cm , a = 0, b = 0, c = 0 , d = 0, e = 0, f = 0;

     e = val / z;

     a = val / x;
     d += a;
     d -= e;

     b = val / y;
     c += b;
     c -= e;

     f = val - ( d+e+c );

     if( c < n )
     {
         f -= ( n-c );
         c = n;
     }
     if( d < m )
     {
         f -= ( m - d );
         d = m;
     }
     //cout << f << ' ' << c << ' ' << d << endl;
     if( f >= 0 && c >= n && d >= m )
        return 1;

     else
        return 0;
 }



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long i, j, st = 0 , en = mx,  a = mx, b, c, mid;

    cin >> n >> m >> x >> y ;
    nn = n+m;
    b = __gcd( x,y);
    c = x*y;
    z = c/b;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        b = chk( mid );
        //cout << mid << ' ' << b << endl;
        if( b == 1 )
            {
                a = min( a, mid );
                en = mid-1;
            }
        else
            st = mid+1;
    }

    cout << a;





    return 0;

}


