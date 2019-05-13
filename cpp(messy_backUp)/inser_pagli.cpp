#include<iostream>
#include<ctime>

using namespace std;

int arr[100000], n;

void insertion( int arr[] )
{
    int k, j;
    for(int i=1;i<n;i++)
    {
        k=arr[i];
        j=i-1;

        while(j>=0&&arr[j]>k )
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}


int main()
{
    int i, j;

    cin >> n ;
    for( i=0; i<n; i++ ) cin >>arr[i];
    insertion(arr);
    for( i=0; i<n; i++ ) cout<<arr[i]<<' ';
    return 0;

}






