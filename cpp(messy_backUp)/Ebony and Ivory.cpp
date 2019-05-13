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

    long long int i, j, x = 0, y, n, m, a, b, c;

    cin >> a >> b >> c;

    y = c;

    while ( c > 0 )
    {
        if( c % a == 0 )
            x = 1;
        else if( c % b == 0 )
            x = 1;

        c -= min(a,b);

    }
    while ( y > 0 )
    {
        if( y % a == 0 )
            x = 1;
        else if( y % b == 0 )
            x = 1;

        y -= max(a,b);

    }

    if( x == 1 )
        cout << "Yes";
    else
        cout << "No";

    return 0;

}

