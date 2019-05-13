#include<iostream>

using namespace std;

int main()
{
    int a,b,x,i=0,n,j;

    cin>>a>>b;

    x=a;
    n=a;

    if(a%2==0&&b==2)
        cout<<(a*2)-1;

    else
    {
        while(n>0)
    {
        j=n;
        n/=b;
        x+=n;
    }

    if(a%2==0&&b%2==0)
        x++;

    while(a>0)
    {
        i=i+(a%b);
        a/=b;
    }
    n=i;
    while(n>0)
    {
        j=n;
        n/=b;
        x+=n;
    }
   cout<<j;

    cout<<x;
    }
}
