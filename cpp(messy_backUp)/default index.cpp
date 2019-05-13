#include<iostream>

using namespace std;

int main()
{
    int a[10111],n,i,d=0,x,b,y,m,z=0;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    d=n;

    for(i=0;i<n;i++,d--)
        for(x=i;x<d;x++)
    {
        if(a[i]>a[x])
            swap(a[i],a[x]);
        if(a[d]<a[x])
            swap(a[d],a[x]);
    }
    i=0;
    while(a[i]+1==a[i+1])
    {
        i++;
    }

    cout<<a[i]+1;

}

