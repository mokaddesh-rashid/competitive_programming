#include<iostream>
#include<string>

using namespace std;

int main()
{
    string k,a,b,c,d,e,f,g,h,l,m,str;

    cin>>k;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cin>>f;
    cin>>g;
    cin>>h;
    cin>>m;
    cin>>l;

    int x=0,y=10,i,j;


    for(i=0;i<8;i++)
    {
        str.assign(k,x,10);
        cout<<str<<endl;

        if(str==a)
            cout<<1-1;
        else if(str==b)
            cout<<2-1;
        else if(str==c)
            cout<<3-1;
        else if(str==d)
            cout<<4-1;
        else if(str==e)
            cout<<5-1;
        else if(str==f)
            cout<<6-1;
        else if(str==g)
            cout<<7-1;
        else if(str==h)
            cout<<8-1;
        else if(str==m)
            cout<<9-1;
        else if(str==l)
            cout<<10-1;

        x+=10;


    }

}
