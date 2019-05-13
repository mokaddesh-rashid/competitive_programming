#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, n, x, y, xx, yy, a, b, fmax = 0, smax = 0, f , s, aa, bb, bal =0, mm=0, nn=0;

    double h, k, l;

    cin >> n >> x >> y >> xx >> yy;

    for( i=0; i<n; i++)
    {
        cin >> f >> s;
        a = ( x - f) * ( x - f);
        b = ( y - s ) * ( y - s );

        a = a + b;



        aa = ( xx - f) * ( xx - f);
        bb = ( yy - s ) * ( yy - s );

        aa = aa + bb;

        mm = max( mm, a);
        nn = max ( nn, aa);

        cout << endl << a << endl << aa << endl << endl;
        if( aa <= smax )
            continue;
        else if ( a <= fmax )
            continue;
        else if ( a < aa )
        {
            fmax = max( fmax, a);
        }
        else if ( aa < a)
        {
            smax = max( smax, aa);
        }
        else
        {
            bal = max( bal, aa);
        }
        //smax = max( smax, a);
    }

    if( bal <= fmax || bal <= smax )
        bal = 0;

    long long int    ans = fmax + smax + bal;

    ans = min( ans, nn);
    ans = min( ans, mm);

     cout << nn << endl << mm << endl;
    cout << ans;





    return 0;

}
