#include <iostream>

using namespace std;


int main ()
{
    int n;

    cin >> n;

    int arr[n+1], i, x, c;

    for( i=0; i<n ; i++)
    {
        cin >> arr[i];

    }

    c = n;

    for( i=0 ; i<n ; i++,c--)
       for( x=0 ; x<c-1 ; x++)
    {
        if( arr[x] > arr[x+1] )
            swap(arr[x],arr[x+1]);
    }

    for( i=0; i<n ; i++)
    {
        cout << arr[i] << ' ';

    }

}
