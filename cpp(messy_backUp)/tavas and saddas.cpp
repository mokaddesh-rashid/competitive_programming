#include<iostream>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int i,n,a=0,b=0,x,z=7,y=4,des,up;

    char str[1111];

    cin>>str;

    x=strlen(str);

    des=str[0]-48;
    for(i=1;i<x;i++)
    {
        up=str[i]-48;
        des*=10;
        des+=up;
    }
    //cout<<des;
    for(i=1;i<x;i++)
    {
        y*=10;
        y+=4;
    }
   // cout<<x;
    for(i=x-1;i>0;i--)
    {
        int c;
        c=pow(2,i);
        a+=c;

    }

     b=a;

    for(i=y;i<=des;i++)
    {
        a=i;

        while(a%10==4||a%10==7)
        {
          a/=10;
        }
      if(a==0)
        b++;
    }

    cout<<b;
}
