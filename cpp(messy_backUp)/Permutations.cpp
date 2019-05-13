#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int n,t;

    cin>>n>>t;

    int arr[n+1],i,j,a,b,c,d,an[n+1];


    for(i=1;i<=n;i++)
    {
        arr[i-1]=i;
    }

    while(t>1)
    {
        for(i=0;i<n;i++)
        cout<<arr[i]<<' ';
        next_permutation(arr,arr+n);
        t--;
        cout<<endl;

    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<' ';


}
