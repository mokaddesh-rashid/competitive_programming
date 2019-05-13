#include<iostream>

using namespace std;

int main()
{
    long int n,x,y;

    cin>>n>>x>>y;

    long long int i,a,b,c;

    a=(y*n)/100;

    if(y*n%100)
        a++;

    b=a-x;

    if(b>0)
        cout<<b;

    else
        cout<<0;
}
