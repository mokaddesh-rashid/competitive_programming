#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a,b,c;
    long long int x=0;


    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);


    a=0;
    b=n-1;

   // while(a<b)
    {
        swap(arr[a],arr[b]);
        //a+=2;
       // b-=2;
    }

     for(i=0;i<n;i++)
        cout<<arr[i]<<' ';
}
