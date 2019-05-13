#include<iostream>
#include<cmath>

using namespace std;

int naive( int a, int b )
{
    int x, y, z;

    x = a;
    y = b;
    z = 0;

    while( x > 0 )
    {
        if( x%2 == 1 )
            z += y;

        y = y << 1;
        x = x >> 1;

    }

    return z;
}


int main()
{
    double a, b, c, d;

    cin >> a >> b;
    c = sqrt(3);
    c /= 4;
    d = naive( (int)a, (int)b );
    c *= d;
    cout << "total area " << c ;

}

