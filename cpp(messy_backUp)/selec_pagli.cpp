#include<iostream>
#include<ctime>

using namespace std;

int arr[100000], n;

void selection( int arr[] )
{
    int p;
    for(int i=0;i<n-1;i++)
    {
        p=i;
        for(int j=i;j<n;j++)
        {
          if(arr[p]>arr[j]) p=j;
        }
        swap(arr[p],arr[i]);
    }
}

int main()
{
    int i, j;

    cin >> n ;
    for( i=0; i<n; i++ ) cin >>arr[i];
    selection(arr);
    for( i=0; i<n; i++ ) cout<<arr[i]<<' ';
    return 0;

}






