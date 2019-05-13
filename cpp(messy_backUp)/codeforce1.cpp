#include<iostream>

using namespace std;

int main()
{
    int a,b,c,i,n,d=-1;
    cin>>a>>b>>c;
    if(a<0)
        a=a*d;
    if(b<0)
        b=b*d;
    if(c<0)
        c=c*d;
    i=a+b;
    n=a+(b-c);
    if(a==0&&b==0&&c%2==0)cout<<"yes";
    else if(c==n||c==i)cout<<"yes";
    else
        cout<<"no";
    return 0;
}
