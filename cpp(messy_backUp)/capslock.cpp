#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int i,x=0,b,a,c,len,z;
    char str[111];

    gets(str);

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        z=str[i];

        if(z<97)
            x++;
    }

    //cout<<x<<endl<<len;
    c=str[0];

    if(len==1)
    {
        if(c>=97)
            str[0]-=32;
        else
            str[0]+=32;
    }
    else if(x==len)
    {
        for(i=0;i<len;i++)
        {

               str[i]=str[i]+32;

        }
    }
    else if(x==len-1&&c>=97)
     {
         for(i=0;i<len;i++)
        {
            if(i==0)
               str[i]-=32;
            else
               str[i]=str[i]+32;

        }
     }

     cout<<str;
}
