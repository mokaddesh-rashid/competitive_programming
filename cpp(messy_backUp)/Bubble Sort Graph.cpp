#include<iostream>

using namespace std;

int t = 0;

void merge_it(int arr[],int start,int mid, int endd)
{
    int n,n2;

    n=(mid-start)+1;
    n2=endd-mid;

    int f_half[n+1],s_half[n2+1],i,j,k;

    for(i=0;i<n;i++)
        f_half[i]=arr[start+i];

    for(i=0;i<n2;i++)
        s_half[i]=arr[mid+1+i];

     i=0;
     j=0;
     k=start;

    while(i<n&&j<n2)
    {
        if(f_half[i]>s_half[j])
        {
            t++;
            arr[k]=f_half[i];
            i++;
            k++;
        }

        else
        {
            arr[k]=s_half[j];
            j++;
            k++;
        }

    }

    while(i<n)
    {
            arr[k]=f_half[i];
            i++;
            k++;
    }

     while(j<n2)
    {
            arr[k]=s_half[j];
            j++;
            k++;
    }

}

void divide(int arr[], int start, int endd)
{
    int mid;

    if( start < endd )
    {


        mid = ( start + endd )/2;
        divide(arr,start,mid);
        divide(arr,mid+1,endd);

        merge_it(arr,start,mid,endd);
    }
}

int main()
{
    int n;

    cin >> n;

    int arr[n+1], i, x, a , b, c;

    for( i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    divide(arr,0,n-1);

    cout<< t <<endl;


}

