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

    long long int i, j, x, y, n, m, a = 0 ;

    cin >> n;

    string str[n];

    for( i=0; i<n; i++)
         cin >> str[i];

    for( i=0; i<n; i++)
    {
        x = 0;

        for( j=0; j<n; j++)
        {
            if( str[i][j] == 'C' )
                x++;
        }


        if( x > 1)
          m = x*(x-1);

        else
         m = 0;

         m /= 2;

        a += m;
    }
    for( i=0; i<n; i++)
    {
        x = 0;

        for( j=0; j<n; j++)
        {
            if( str[j][i] == 'C' )
                x++;
        }

        if( x > 1)
          m = x*(x-1);

        else
         m = 0;

         m /= 2;

        a += m;
    }

    cout << a;

    return 0;

}

