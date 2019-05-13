#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],i,j,a,b,c;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n,greater<long long int>());

    cout<<arr[0]<<' '<<arr[1];


}
