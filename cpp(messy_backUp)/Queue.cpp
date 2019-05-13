#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],i,a,c=0,x=n;

    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    // for(i=0;i<n;i++)
       // cout<<arr[i]<<' ';

   // cout<<endl;

     for(i=0;i<n;i++)
       {
           if(c>arr[i])
              x--;
           else
              c=c+arr[i];

       }

       cout<<x;




}
