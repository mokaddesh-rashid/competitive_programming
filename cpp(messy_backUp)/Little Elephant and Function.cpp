#include<iostream>


using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n],i,x,a,b,c;

    for(i=0;i<n;i++)
    {
        arr[i]=i+1;
    }

    for(i=n-1;i>0;i--)
      swap(arr[i],arr[i-1]);

     for(i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }

}
