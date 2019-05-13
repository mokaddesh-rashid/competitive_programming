
#include<iostream>

using namespace std;

int main()
{
    int x,y;

    cin>>x;

    y=x*x;

    int i,n,ar[y+1],a=0,b,c;

    for(i=0;i<x;i++)
    {
        c=0;
       while(c!=x/2)
       {
           a++;
           cout<<a<<' ';
           c++;

       }

       c=0;
       while(c!=x/2)
       {
           cout<<y<<' ';
           c++;
           y--;
       }

       cout<<endl;
    }


}
