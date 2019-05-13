#include<iostream>

using namespace std;

int main()
{
    long long int b,r,x,a;

    cin>>b>>r;

    a=min(b,r);
    x=max(b,r)-min(b,r);

    cout<<a<<' '<<x/2;
}
