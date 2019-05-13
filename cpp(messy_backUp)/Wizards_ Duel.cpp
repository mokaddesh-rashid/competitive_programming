#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    double n,p,q,a;

    cin>>n>>p>>q;

    a=n*(p/(p+q));

    printf("%.6lf",a);
}
