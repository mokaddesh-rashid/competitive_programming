#include<iostream>

using namespace std;

int naive( int a, int b )
{
    int x, y, z;

    x = a;
    y = b;
    z = 0;

    while( x-- )
    {
        z += y;

    }

    return z;
}


int main()
{
    int a, b;

    cin >> a >> b;

    cout << "total area " << naive( a, b );

}
