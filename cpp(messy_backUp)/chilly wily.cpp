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

    long long int n, x=210 , i, j, a=1, b, y;

    cin >> n;

    y = 1;

    while ( y < n )
    {
        a *= 10;
        y++;

        a %= 210;
    }

    if( n < 3 )
        cout << -1;
    else if( n == 3 )
        cout << 210;
    else
    {
        x -= a;

    for( i=0; i< n-3; i++)
    {
        if(i==0)
            cout << 1;
        else
            cout << 0;
    }

    if( x/100 == 0 )
        cout << 0;

    cout<< x;
    }







}

