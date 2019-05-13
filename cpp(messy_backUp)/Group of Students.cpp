#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;


    int arr[n+1],bru[n+1],i,x,y,a=0,b,c,d=0;

    arr[0]=0;

    for(i=1;i<=n;i++)
    {
        cin>>arr[i];

        a+=arr[i];

        bru[i]=a;
    }


    cin>>x>>y;

    for(i=1;i<=n;i++)
    {
        b=bru[i];
        c=bru[n]-bru[i];

       // cout<<b<<' '<<c<<' '<<i<<endl;

        if((b>=x&&b<=y)&&(c>=x&&c<=y))
             d=i+1;

    }

    cout<<d;


}
