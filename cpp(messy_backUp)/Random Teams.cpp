#include<iostream>

using namespace std;

int main()
{
    long long int x,i,a,b,c,n,m,d=0,e;

    cin>>n>>m;

    a=n/m;
    b=n%m;
    if(n%m!=0)
    {
        d=(a+1)*a;
        d/=2;
        d*=b;
       m=m-b;
    }

    c=a*(a-1);
    c/=2;
    c*=m;

    m=m+b;
    cout<<c+d<<' ';
    b=m-1;
    b=n-b;
    a=b*(b-1);
    a/=2;
    cout<<a;
}
