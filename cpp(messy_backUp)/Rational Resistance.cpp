#include<iostream>


using namespace std;

int main()
{
    long long int a,b,d,x=0,c;



    cin>>a>>b;

    while(a!=0)
    {

       c=min(a,b);
       d=max(a,b);
       a=c;
       b=d;
       x+=(d/c);
       b=c;
       a=d%c;



    }

     // cout<<a<<' '<<b<<endl;
   // c=max(a,b);
   //if(a==1&&b==1)
     //cout<<1;
   //else
      cout<<x;




}
