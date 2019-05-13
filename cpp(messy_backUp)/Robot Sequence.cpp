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

    long long int i, j, x, y, n, m, a=0;


    cin >> n;

    string str;

    cin >> str;

    for( i=0 ; i<n ; i++ )
    {
        x = 0;
        y = 0;

        for( j=i; j<n; j++)
        {
            if( str[j] == 'U' )
                x++;
            else if( str[j] == 'D' )
                x--;
            else if( str[j] == 'R' )
                y++;
            else if( str[j] == 'L' )
                y--;

            if( x == 0 && y == 0 )
                a++;

        }
    }

    cout << a;

    return 0;

}

