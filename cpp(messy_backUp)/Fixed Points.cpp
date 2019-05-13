#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,x=0,a,ans=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }

     for(i=0;i<n;i++)
    {
        if(arr[i]==i)
            ans++;
        else if(i==arr[arr[i]])
            x=2;
        else if(x==0)
            x=1;

    }

    cout<<ans+x;

}
