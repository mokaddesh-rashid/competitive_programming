#include<iostream>


using namespace std;

int main()
{
    long long int a,b=0,x=0,c=1,d=0;

    cin>>a;

    if(a<0)
        a*=-1;

    while(b<a)
    {

           b+=c;
           c++;
           d=0;
           x++;
        //cout<<b<<endl;
    }

   if(b==a)
    cout<<x;
   else if(a==1000000000)
    cout<<x+2;
   else if(a%2==0)
    cout<<x+1;
   else
    cout<<x;


}
