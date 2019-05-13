#include<iostream>

using namespace std;


int main()
{
    int ar[111],n,i;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>ar[i];

    int x,m;

    x=n-1;

    for(i=0;i<n;i++,x--)
        for(m=i;m<x;m++)
    {
        if(ar[i]>ar[m])
            swap(ar[i],ar[m]);
        if(ar[x]<ar[m])
            swap(ar[x],ar[m]);
    }

    for(i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
