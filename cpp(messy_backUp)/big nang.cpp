#include<iostream>

using namespace std;


int main()
{
    int x,i,n,a=5,b=2,y=5;

    cin>>x;

    if(x<6)
    {
        if(1==x)
        cout<<"Sheldon";
    else if(2==x)
        cout<<"Leonard";
    else if(3==x)
        cout<<"Penny";
    else if(4==x)
        cout<<"Rajesh";
    else if(5==x)
        cout<<"Howard";
    }

   else
   {
   	 while(a+y*2<x)
    {
        y=y*2;
        a+=y;
        b*=2;
    }

    if(a+b>=x)
        cout<<"Sheldon";
    else if(a+b+b>=x)
        cout<<"Leonard";
    else if(a+b+b+b>=x)
        cout<<"Penny";
    else if(a+b+b+b+b>=x)
        cout<<"Rajesh";
    else if(a+b+b+b+b+b>=x)
        cout<<"Howard";
   }

}
