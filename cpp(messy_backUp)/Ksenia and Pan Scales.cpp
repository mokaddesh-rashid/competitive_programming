#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str,rest;

    cin>>str;
    cin>>rest;

    long long int x=0,i,y=0,a,b=0,c=0,z;

    for(i=0;i<str.size();i++)
    {
        if(str[i]=='|')
            b=1;
        else if(b==0)
            x++;
        else
            y++;
    }

    z=rest.size();

    a=max(x,y)-min(x,y);

    a=z-a;

    //cout<<a<<endl;



    if(max(x,y)-min(x,y)>z||a%2)
        cout<<"Impossible";

     else if(a>0&&x<y)
    {
        int m;
        for(i=0;i<a/2+(y-x);i++)
            cout<<rest[i];
        cout<<str;
        m=i;
        for(i=m;i<rest.size();i++)
          cout<<rest[i];

    }
     else if(a>0&&x>y)
    {
        int m;
        for(i=0;i<a/2;i++)
            cout<<rest[i];
        cout<<str;
        m=i;
        for(i=m;i<rest.size();i++)
          cout<<rest[i];

    }

    else if(a>0)
    {
        for(i=0;i<a/2;i++)
            cout<<rest[i];
        cout<<str;
        for(i=a/2;i<a;i++)
          cout<<rest[i];

    }

     else if(x>y)
    {
      cout<<str;
      cout<<rest;
    }
    else
    {

      cout<<rest;
      cout<<str;

    }



}
