#include<iostream>

using namespace std;

int main()
{
    long long int n,x,t,p;

    cin>>n>>p;

    x=n/2;

    if(n%2)
        x++;

    if(p<=x)
        cout<<2*p-1;

    else
        cout<<(p-x)*2;
}
