#include <iostream>

using namespace std;


int main ()
{
    int n;

    cin >> n;

    int arr[n+1], i, x, pos, minn;

    for( i=0; i<n ; i++)
    {
        cin >> arr[i];

    }



    for( i=0 ; i<n ; i++)
    {
       for( x=i ; x<n ; x++)
    {
        if( x==i || minn > arr[x] )
            {
                pos = x;
                minn = arr[x];
            }

    }

    swap( arr[pos], arr[i]);

    }

    for( i=0; i<n ; i++)
    {
        cout << arr[i] << ' ';

    }

}
