#include<iostream>

using namespace std;

int main()
{
    long long int a,b,c,x,y,z;

    cin>>a>>b>>c;


    y=a+b+c;

    x=max(a,b);
    x=max(x,c);

    z=y/3;
    y=y-x;


    if(y>z)
        cout<<z;
    else
       cout<<y;




}
