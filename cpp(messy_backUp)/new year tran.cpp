
#include<iostream>

using namespace std;

int main()
{
    long long int n,i,t=0,x=1,a,b;

    cin>>n>>t;

    int ar[n+1];
    ar[0]=1;
    for(i=0;i<n-1;i++)
    {
        cin>>a;
        x=i+a+1;
        ar[i+1]=x;
        if(x==t)
            b=i;
    }

    for(x=0;x<=i;x++)
    {
        if(ar[x]==i)
            t=1;
    }

    if(t==1)
    cout<<"YES";

    else
    cout<<"NO";
}
