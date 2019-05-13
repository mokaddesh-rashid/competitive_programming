#include <iostream>

using namespace std;


int main ()
{
    int n;

    cin >> n;

    int arr[n+1], i, x, pos, value;

    for( i=0; i<n ; i++)
    {
        cin >> value;

        arr[i] = value;

        if( i != 0 )
       {
          x = i;
          while (x>0 && arr[x] < arr[x-1])
        {
           arr[x] = arr[x-1] ;
            x--;
        }

        arr[x] = value;


       }

    }


    for( i=0; i<n ; i++)
    {
        cout << arr[i] << ' ';

    }

}
