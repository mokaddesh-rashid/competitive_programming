#include<iostream>

using namespace std;

int main()
{
    int a,n,d,x=0,i;

    cin>>n>>d;

    int b[n+2];

    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }

    for(i=1;i<n;i++)
    {
        if(b[i]<=b[i-1])
       {
         a=b[i-1]-b[i];
         a=a/d+1;
         b[i]=b[i]+(a*d);
         x=x+a;

       }
    }

    cout<<x;

}
