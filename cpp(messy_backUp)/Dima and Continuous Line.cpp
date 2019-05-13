#include<iostream>

using namespace std;


int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,j,a,b,c,d,x=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n-3;i++)
    {
        a=min(arr[i],arr[i+1]);
        b=max(arr[i],arr[i+1]);

        for(j=i+2;j<n-1;j++)
        {
           c=min(arr[j],arr[j+1]);
           d=max(arr[j],arr[j+1]);
           //cout<<a<<' '<<c<<' '<<b<<' '<<d<<endl;
           if(a<c&&c<b&&b<d)
            x=1;
           if(c<a&&a<d&&d<b)
            x=1;
        }
    }

    if(x==1)
        cout<<"YES";

    else
        cout<<"NO";

}
