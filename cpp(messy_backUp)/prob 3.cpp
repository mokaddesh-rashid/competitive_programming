#include<iostream>

using namespace std;

int n;

int searchh( int arr[] )
{
    int maxx = 0;

    for( int i = 0; i<n; i++ )
    {
        maxx = max( arr[i], maxx );

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

    cout << "Maxx num " << a ;

}

