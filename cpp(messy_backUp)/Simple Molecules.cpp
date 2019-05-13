#include<iostream>

using namespace std;


int main()
{

    long long int a,b,c,x=0,y=0,z=0;


    cin>>a>>b>>c;

    while(a>0)
    {
        if(c<=0&&b<=0)
            break;
        if(b>c)
        {
            a--;
            b--;
            x++;
        }
        else
        {
            a--;
            c--;
            z++;
        }

    }

    while(b>0)
    {
        if(a<=0&&c<=0)
            break;

        if(a>c)
        {
            x++;
            a--;
            b--;
        }
        else
        {
            b--;
            c--;
            y++;
        }
    }

    if(a!=0||b!=0||c!=0)
        cout<<"Impossible";
    else
        cout<<x<<' '<<y<<' '<<z;



}
