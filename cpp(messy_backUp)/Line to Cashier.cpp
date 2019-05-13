#include<iostream>

using namespace std;


int main()
{
    long long int n;

    cin>>n;

    int arr[n+1],i,j,x,maxx,a;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n;i++)
    {
        x=0;
        for(j=0;j<arr[i];j++)
        {
           cin>>a;
           x+=a;
        }
        x*=5;
        x=x+(arr[i]*15);
        if(i==0)
        {
            maxx=x;
        }
        else
            maxx=min(maxx,x);
    }

    cout<<maxx;
}
