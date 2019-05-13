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

    long long int a, b, i, j, x=0, arr[11] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 } , y, z;

    cin >> a >> b;

    while( a <= b )
    {
        y = a;

        while( y > 0 )
        {
            z = y%10;
            x += arr[z];
            y /= 10;
        }

        a++;
    }

    cout << x;


    return 0;

}

