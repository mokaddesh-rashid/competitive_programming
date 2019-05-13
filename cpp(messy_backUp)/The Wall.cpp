#include<iostream>

using namespace std;

int main()
{
    int x,y,a,b,z;

    cin>>x>>y>>a>>b;

    int c=x,d=y,i;

    while(y%x!=0)
    {
        z=x;
        x=y%x;
        y=z;

    }

    c=(c*d)/x;

    a--;

    a=a/c;

    b=b/c;

    cout<<b-a;





}
