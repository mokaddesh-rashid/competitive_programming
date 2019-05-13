#include <iostream>

using namespace std;

void heap_remove(int arr[], int &n)
{
    int i,x,a;

    swap(arr[1],arr[n-1]);

    n--;

    x=1;

    while( arr[x] < arr [2*x] || arr[x] < arr[2*x+1] )
    {
        if( arr[2*x] > arr[2*x+1] && 2*x < n )
        {
            swap(arr[x],arr[2*x]);
            x = 2*x;
        }
        else  if( arr[2*x] < arr[2*x+1] && 2*x+1 < n )
        {
            swap(arr[x], arr[2*x +1]);
            x = 2*x +1;
        }
        else if( arr[x] < arr[2*x] && 2*x < n)
            {
            swap(arr[x],arr[2*x]);
            x = 2*x;
            }

        else
            break;


    }
}

int main()
{
    int n;

    cin >> n ;
    n++;

    int arr[n+1] , x, i;

    for( i=1; i<n; i++)
    {
        cin >> arr[i];

        x = i;

        while( x>1 && arr[x] > arr[x/2] )
        {
            swap(arr[x] , arr[x/2]);

            x = x/2;
        }

    }
    for( i=1; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
    //cout << endl;
    int a = n;

    while(a>1)
    {
        heap_remove( arr,a);
    }

    for( i=1; i<n; i++)
    {
        cout << arr[i] << ' ';
    }

}
