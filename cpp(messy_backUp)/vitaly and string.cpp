#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int a,b,i,n,c=0,d;

    char st[111],str[111];

    cin>>st>>str;

    d=strlen(st);

    for(i=0;i<d;i++)
    {
        int x,y;
        a=st[i];
        b=str[i];
        x=st[i-1];
        y=str[i-1];

      if(b-a>1)
        {
             str[i]=b-1;
             c++;
        }

     if(b-a<1&&x<y)
     {
         str[i]='a';
          c++;
     }


    }

    if(c==0)cout<<"No such string";

    else
         for(i=0;i<d;i++)
            cout<<str[i];
    return 0;
}


