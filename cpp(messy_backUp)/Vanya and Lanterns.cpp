#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    long long int n,l;

    double x=0,y;

    cin>>n>>l;

    long long int arr[n+1],i,j,a,b,c;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);


    for(i=0;i<n-1;i++)
    {
        //cout<<arr[i+1]<<' '<<arr[i]<<' ';
        a=arr[i+1]-arr[i];
        y=a;
        y=y/2;
        x=max(y,x);
        //cout<<y<<endl;
    }

    y=arr[0];
    x=max(x,y);
    y=(l-arr[n-1]);
    x=max(x,y);

    printf("%.2lf",x);


}
