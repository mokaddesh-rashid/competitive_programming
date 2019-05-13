#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int  n,i;

    cin>>n;


    double x[n+1],y[n+1],a,b,c=0,d,k;


    cin>>k;


    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];

        if(i>0)
        {
          a=(x[i]-x[i-1])*(x[i]-x[i-1]);
          b=(y[i]-y[i-1])*(y[i]-y[i-1]);

          //cout<<a<<' '<<b<<endl;

          a=a+b;

          a=sqrt(a);

          c+=a;
        }
    }

    c*=k;

    printf("%.6lf",c/50);



}
