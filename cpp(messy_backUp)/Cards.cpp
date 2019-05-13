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

    long long int i, j, x, y, n, m, r=0, g=0, b=0;

    cin >> n;

    char ch;

    for( i=0; i<n ; i++ )
    {
        cin >> ch;

        if( ch == 'R' )
            r++;
        else if( ch == 'G' )
            g++;
        else if( ch == 'B' )
            b++;

    }

    if( r == n )
        cout << 'R';
    else if( g == n )
        cout << 'G';
    else if( b == n )
        cout << 'B';
    else if( n == 2 && b == 1 && g == 1 )
        cout << "R";
    else if( n == 2 && b == 1 && r == 1 )
        cout << "G";
    else if( n == 2 && r == 1 && g == 1 )
        cout << "B";
    else if( r == g && b == r )
        cout << "BGR";
    else if( r >= 1 && g >= 1 && b >= 1 )
        cout << "BGR";
    else if( r >= 2 && g >= 2 )
        cout << "BGR";
    else if( r >= 2 && b >= 2 )
        cout << "BGR";
    else if( g >= 2 && b >= 2 )
        cout << "BGR";
    else if( r == 0 || g == 0 || b == 0 )
    {
        if( r >= 2 )
           cout << "BG";
        else if( g >= 2 )
           cout << "BR";
        else if( b >= 2 )
           cout << "GR";



    }
    else
       cout << "BGR";






    return 0;

}

