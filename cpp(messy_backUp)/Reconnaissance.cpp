#include<iostream>

using namespace std;

int main()
{
    long long int i,n,a,b,d,z=0,x;

    cin>>n>>d;

    int height[n+1];

    for(i=0;i<n;i++)
    {
        cin>>height[i];
    }

    for(i=0;i<n;i++)
        for(x=0;x<n;x++)
    {
        if(i==x)
            continue;
       b=height[i]-height[x];

       if(b<=d&&b>=-d)
        z++;
    }

    cout<<z;
}
