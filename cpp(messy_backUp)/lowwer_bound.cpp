#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int lower( int arr[], int st, int en, int val)
{
    int mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            en = mid - 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}

int upper( int arr[], int st, int en, int val)
{
    int mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            st = mid + 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m, st, en;

    cin >> n;

    int arr[n+1];



    for( i=0; i<n; i++ )
        cin >> arr[i];

    sort( arr, arr+n );

     for( i=0; i<n; i++ )
        cout << arr[i] << ' ' ;

    cout << endl ;

    for( i=0; i<n; i++)
        {
            cin >> m;

            cin >> st >> en ;

            x = lower( arr, st, en-1, m ) ;
            y = upper( arr, st, en-1, m ) ;

            cout << x << ' ' << y << endl ;
        }

    return 0;

}


