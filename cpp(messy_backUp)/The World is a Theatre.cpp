#include<iostream>


using namespace std;


int main()
{
    long long c,m,t,a=1,b=1,x,y;

    cin>>c>>m>>t;


    x=c;
   // y=t-1;
    while(x>4)
    {
        a=a*x;
        x--;
    }

    y=t-4;
    x=m;
    while(y>0)
    {
        b=b*x;
        x--;
        y--;
    }

    cout<<b*a;



}
