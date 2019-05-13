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

    long long int i, j, x, y, n, m, a, b, c=0;

    string str;

    cin >> str;

    x = 0;
    y = str.size()-1;
    n = str.size();

    int arr[n+1];

    for( i=0; i<n ; i++, x++, y-- )
    {


        if( x <= y )
        {
            a = str[x]-48;
            b = str[y]-48;

        if ( a == b && a % 2 )
       {
            arr[x] = a ;
            arr[y] = 0 ;
       }

       else if ( a == b  )
       {
            arr[x] = a / 2;
            arr[y] = a / 2;
       }


        if( x == y )
        {
            if( a % 2 )
                c = 1;
        }

        }
        else
            break;
    }

    if( c == 1 )
        cout << 0;
    else
    {
        for( i=0; i<n ; i++ )
        {
            cout << arr[i];
        }
    }

}

