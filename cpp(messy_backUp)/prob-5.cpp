#include<iostream>

using namespace std;

int n;

int searchh( int arr[] )
{
    int maxx = 0;

    for( int i = 0; i<n; i++ )
    {
        if( arr[maxx] < arr[i] )
            maxx = i;

    }

    return maxx;
}


int main()
{
    int a, b, arr[100010];

    cin >> n;

    for( int i=0; i<n; i++ )
        cin >> arr[i];

    a = searchh( arr );

    cout << "winner " << a ;

}


