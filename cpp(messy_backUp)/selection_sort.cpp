#include<iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int arr[n+1] , i, a=0 , pos, minn, c, j;

     for( i=0; i<n; i++)
        cin >> arr[i];



     for ( i=0; i<n; i++ )
     {
         for( j=i ; j<n; j++ )
         {
             if( j == i )
             {
                 pos = i;
                 minn = arr[i];
             }

             else if( minn > arr[j] )
             {
                 pos = j;
                 minn = arr[j];
             }
         }

         swap( arr[i] , arr[pos] );
     }

     for( i=0; i<n; i++ )
        cout << arr[i] << ' ';


}
