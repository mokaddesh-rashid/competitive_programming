#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int height[n+1],d,i,x=0,b,a,y=0;

    for(i=0;i<n;i++)
        cin>>height[i];

    for(i=0;i<n-1;i++)
    {
        x=height[i]-height[i+1];
        if(x<0)
            x*=-1;

        if(x<y)
        {
          y=x;
          a=i;
          b=i+1;
        }
    }

     x=height[i]-height[n-1];
        if(x<0)
        x*=-1;
        if(x<y)
        {
          y=x;
          a=i;
          b=n-1;
        }

cout<<a<<' '<<b;
}
