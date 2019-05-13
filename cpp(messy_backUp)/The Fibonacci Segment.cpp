#include<iostream>


using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],i,j,x=2,maxx=2;

    for(i=0;i<n;i++)
        cin>>arr[i];


    for(i=2;i<n;i++)
    {
        if(arr[i]==arr[i-1]+arr[i-2])
            x++;
        else
            x=2;

        maxx=max(x,maxx);
    }

    if(n<=2)
        cout<<n;
    else
        cout<<maxx;
}
