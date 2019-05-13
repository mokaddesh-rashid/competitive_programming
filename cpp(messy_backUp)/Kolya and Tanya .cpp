#include<iostream>


using namespace std;

int main()
{
    long long int n,x=1000000007,t=1,a,m=1,b,c;

    cin>>n;

    n*=3;
    a=n/3;

    while(n>0)
    {
       t=t*3;
       t%=x;
       n--;
    }

    while(a>0)
    {
       m=m*7;
       m%=x;
       a--;
    }

    //cout<<m<<' '<<t<<endl;


    if(t<m)
    {
      b=t-m;
      b=x+b;

      cout<<b;
    }

    else
      cout<<t-m;
}
