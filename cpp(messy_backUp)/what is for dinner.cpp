#include<iostream>

using namespace std;

int main()
{
    long long int i,n,m,k,ar[1111],b,c,x,y,z;

    cin>>n>>m>>k;

    for(i=0;i<m;i++)
        ar[i]=99999999;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;

        if(ar[x-1]>y)
            ar[x-1]=y;
    }
    x=0;
    for(i=0;i<m;i++)
        x+=ar[i];

    if(x>k)
    cout<<k;

    else
    cout<<x;
}
