#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;


    cin>>n>>m;

    int arr[n+1],i,x=0,a,b,c;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(i=0;i<n;i++)
    {
        if(m==0)
            break;
        if(arr[i]<0)
            x+=arr[i];
        m--;
    }


    if(x<0)
            x*=-1;

    cout<<x;
}
