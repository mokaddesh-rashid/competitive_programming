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

    long long int i, j, x, y, n, m, a = 0, b ;

    cin >> n >> m;

    long long int arr[n+1];

    for( i=0; i<n; i++)
    {
        cin >> x;

        if( x % m == 0 )
            a = 1;

        arr[i] = x % m ;
    }

    sort( arr, arr+n );

    i = 0;
    j = 0;
    b = 0;

    while( j < n || i < n )
    {
        //cout << b << endl;
        if ( b == m  )
        {
            a = 1;
            break;
        }
        else if ( ( b < m || i == j ) && j < n )
        {
           b += arr[j];
           b %= m;
           j++;
        }
        else
        {
           b -= arr[i];
           b %= m;
           i++;
        }

        if ( b == 0 && i != j  )
        {
            a = 1;
            break;
        }
    }

    if( a == 0 )
        cout << "NO";

    else
        cout << "YES";

    //cout << a ;

    return 0;

}

