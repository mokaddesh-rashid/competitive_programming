#include<iostream>

using namespace std;


int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+2],i,j,a,b,c,x=0,y,fi,se;

    arr[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        x+=a;
        arr[i]=x;
    }

    for(i=0;i<=n;i++)
    {
       cout<<arr[i]<<' ';
    }

    cin>>a>>b;

    c=(a+b)/2;

     if(a==b)
    {
       x=max(arr[n]-arr[a-1],arr[a]);
       cout<<x<<' '<<x;
    }

    else if(a<b)
    {
        cout<<arr[c]<<' '<<arr[n]-arr[c];
    }
    else if(a>b)
    {
        cout<<arr[n]-arr[c-1]<<' '<<arr[c-1];
    }
}
