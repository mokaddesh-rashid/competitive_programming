#include<iostream>

using namespace std;

int main()
{
    int str[111];

    int len,t,i,n,a,b,x,y;

    cin>>len;

    for(i=0;i<len;i++)
      cin>>str[i];

    x=0;
    y=1001;

    for(i=0;i<len;i++)
    {
        if(x<str[i])
            x=str[i];
         if(y>str[i])
            y=str[i];
    }

    for(i=0;i<len;i++)
    {
        if(str[i]==x)
            {
                a=i;
                break;
            }

    }
    for(i=len-1;i>=0;i--)
    {
        if(str[i]==y)
            {
                b=i;
                break;
            }

    }

    x=a;
    y=len-b;

    cout<<x+y;



}

