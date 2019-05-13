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

    long long int i, j, x, y, n, m, a=0, b, c;

    cin >> n;

    long long int arr[n+1];


    for( i=0; i<n; i++)
        cin >> arr[i];

    sort ( arr, arr+n, greater<long long int> () );

    for( i=0; i<n; i++)
    {
        //cout << arr[i] << ' ' << x << endl;
        if( i == 0 )
            x = arr[i];
        else if( x > arr[i] )
            x = arr[i];

        y = min( x, arr[i]);

        a += y;

       if( x > 0)
             x--;
    }

    cout << a;

    return 0;

}

