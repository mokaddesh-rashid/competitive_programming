#include<iostream>

using namespace std;

int main()
{
    int maxx=0,n,b;

    cin>>n>>b;

    int arr[n+1],i,j,x,y,z,a,c,d=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxx=b;

    for(i=0;i<n;i++)
    {
        x=0;
        d=0;
        for(j=i+1;j<n;j++)
        {
           x=max(x,arr[j]);
        }
        //cout<<x<<endl;
        if(x>arr[i])
        {

            a=b/arr[i];
            c=b%arr[i];
            d=(x*a)+c;
            //cout<<a<<' '<<c<<' '<<x<<' '<<d<<endl;
        }
        maxx=max(d,maxx);
    }

    cout<<maxx;
}
