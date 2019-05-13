#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char ch,str[1111];
    int i,x=1,len,n;

   cin>>str;

   len=strlen(str);

   for(n=0;n<len;n++)
    {
    	if(str[len-1]=='.'||str[len-1]=='/'||str[len-1]=='@')
    	break;
        ch=str[n];
        i=ch;

        if((x==1&&ch=='/')||(x==3&&ch=='@')||(n==0&&ch=='@'))
        {
        	x=0;
        	break;
        }

        if((ch=='/'&&x==3)||(ch=='@'&&x==2))
         {
            x=0;
            break;
        }
        if(ch=='@')
            x=2;
        if(ch=='/')
            x=3;



         if(ch=='@'&&str[n+1]=='.')
            {
                x=0;
                break;
            }
        else if(ch=='@'||ch=='/')
        continue;
        else if(str[n]=='.'&&str[n+1]=='.')
            {
                x=0;
                break;
            }

          else if(str[n]=='.'&&str[n+1]=='/')
            {
                x=0;
                break;
            }

        else if(x==2&&ch=='.')
            continue;

        else if(x==1||x==2||x==3)
        {
             if((i>=65&&i<=95)||(i>=97&&i<=122)||(i==95||i==44)||(i>=48&&i<=57))
            continue;
        else
        {
            x=0;
            break;
        }
        }


    }

    if(x>=2)
        cout<<"YES";
    else
        cout<<"NO";
}
