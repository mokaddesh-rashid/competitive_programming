#include<iostream>

using namespace std;


int main()
{
    int n,k;

    cin>>n>>k;

    int arr[n+1],i,a=0,b,c,x=-1,y=-1;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(i==k-1)
        {
            x=arr[i];
        }

        if(x!=arr[i]&&x!=-1)
        {
            a=1;
        }
    }
   // cout<<x;

    if(a==1)
        cout<<-1;
    else
    {

    for(i=0;i<n;i++)
    {

        if(arr[k-1]!=arr[i])
        {
            a=i+1;
        }
    }

    cout<<a;
    }
}
