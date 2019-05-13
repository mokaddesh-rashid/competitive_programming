#include <iostream>

using namespace std;

struct node
{
    int f, s;
};

void merge_it( int arr[], int start , int mid , int endd)
{
    int n1,n2,i,j,k;

    n1 = mid - start + 1;
    n2 = endd -mid ;

    int first[n1+1],second[n2+1];

    for( i=0; i<n1 ; i++)  //max (n1,n2)
    {
        first[i] = arr[start+i];
    }
    for( i=0; i<n2 ; i++)  //max (n1,n2)
    {
        second[i] = arr[mid+i+1];
    }

    i=0;
    j=0;
    k=start;

    while(i<n1 && j < n2)
    {
        if( first[i] < second [j])
        {
            arr[k] = first[i];
            i++;
            k++;
        }

        else
        {
            arr[k] = second[j];
            j++;
            k++;
        }
    }

    while(i < n1)
    {

            arr[k] = first[i];
            i++;
            k++;
    }

    while(j < n2)
    {
            arr[k] = first[j];
            j++;
            k++;
    }
}

void divide (int arr[], int start, int endd)
{
    if( start < endd )
    {
        int mid =( start + endd ) / 2;

         divide(arr, start, mid);
         divide(arr, mid+1, endd);

         merge_it(arr, start, mid, endd);
    }
}

int main()
{
    int n;

    cin >> n;

    int arr[n+1],i,x,a,b;

    for( i=0 ; i<n ; i++)
        cin >> arr[i];

    divide(arr, 0, n-1);

     for( i=0 ; i<n ; i++)
        cout << arr[i] << ' ';
}
