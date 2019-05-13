#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int a,b,c;

    cin>>a>>b>>c;

    long long int s1,s2,s3;

    s1=a;
    s2=b;
    s3=c;


    a=(s1*s2)/s3;
    a=sqrt(a);

    b=(s1*s3)/s2;
    b=sqrt(b);

    c=(s2*s3)/s1;
    c=sqrt(c);

    cout<<4*(a+b+c);
}
