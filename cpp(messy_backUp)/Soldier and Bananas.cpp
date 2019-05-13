#include<iostream>

using namespace std;

int main()
{
    long long int k,n,w,i,x=0,a;

    cin>>k>>n>>w;

    for(i=0;i<w;i++)
    {
        a=(i+1)*k;
        x=x+a;
    }
    if(x<=n)
        cout<<0;
    else
    cout<<x-n;
}
