#include<iostream>

using namespace std;

int main ()
{
    int u,v,t,d,a=0,b=0,x,len,y=0,i;

    cin>>u>>v>>t>>d;

    x=u;
    y=u;
    for(i=2;i<=t;i++)
    {
       if(d*(t-i)<(d+x-v)&&b==0)
       {
           a=(d+x-v)-(d*(t-i));
           x-=a;
           b=1;
           y=y+x;
       }
       else if(d*(t-i)<(d+x-v)&&b==0&&u>v)
       {
           a=(x-v)-(d*(t-i));
           x-=a;
           b=1;
           y=y+x;
       }

       else  if(b==0)
        {
            x+=d;
            y=y+x;
        }
        else if(b==1)
        {
            x-=d;
            y=y+x;
        }

    }

    cout<<y;
}
