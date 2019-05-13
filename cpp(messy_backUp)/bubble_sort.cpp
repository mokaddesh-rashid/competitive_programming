#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a=0,j,c=0;

     for(i=0;i<n;i++)
        cin>>arr[i];

    for(i=0;i<n;i++)
    {
        a=0;
        for(int x=1;x<n;x++)
    {

        if(arr[x]<arr[x-1])
           {
               c++;
                swap(arr[x],arr[x-1]);
                a=1;

           }
    }

     if(a==0)
           break;
    }

     for(i=0;i<n;i++)
        cout<<arr[i]<<' ';

    cout<<endl<<c;
}
