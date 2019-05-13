#include<iostream>

using namespace std;

int main()
{
    int t;

    cin>>t;

    int i,a,n,b,x=0,y=0,c;

    for(i=0;i<t;i++)
    {
        cin>>a;

        if(a==5)
            x++;
        else
            y++;
    }
    a=x;
    if(x==0||y==0)
        cout<<0;
    else
    {
        while((a*5)%9!=0)
        {
            a--;
        }
    }

    for(i=0;i<=a;i++)
    {
        cout<<5;
    }
     for(i=0;i<=y;i++)
    {
        cout<<0;
    }

}
