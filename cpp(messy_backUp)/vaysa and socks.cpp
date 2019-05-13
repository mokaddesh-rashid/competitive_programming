#include<iostream>

using namespace std;

int main()
{
    int n,m,i=0,x=0,a,b=0;

    cin>>n>>m;

    a=n;
    b=m;
    x=n;

    while(a>=b)
    {
        i=i+a%b;
        a=a/b;

        x+=a;
    }

    cout<<x+a/b;
}
