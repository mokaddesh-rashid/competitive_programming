#include<iostream>
#include<cstring>

using namespace std;


int main()
{
    char str[10*10*10*10*10],line[111],lin[111];

    cin>>str;
    cin>>line>>lin;

    int a,b,c,i,n,d=0,x=0,e=0;

    a=strlen(str);
    b=strlen(line);
    c=strlen(lin);

    for(i=0;i<a;i++)
    {
        if(d==0)
        {
            if(str[i]==line[0])
        {
            for(n=0;n<b;n++)
            {
                if(str[i+n]==line[n])
                    x++;
                if(x==b)
                    {
                       d++;
                       i=i+n;
                   }
                else if(str[i+n]!=line[n])
                    break;
            }
            x=0;
        }
        }

        else if(d==1)
        {
            if(str[i]==lin[0])
        {
            for(n=0;n<c;n++)
            {
                if(str[i+n]==lin[n])
                    x++;
                if(x==c)
                    {
                       d++;
                       i=i+n;
                    }
                else if(str[i+n]!=lin[n])
                    break;
            }
            x=0;
        }
        }
    }
    //cout<<d;

    //strrev(str);


     for(i=a-1;i>=0;i--)
    {
        if(e==0)
        {
            if(str[i]==line[0])
        {
            for(n=0;n<b;n++)
            {
                if(str[i-n]==line[n])
                    x++;
                if(x==b)
                   {
                       e++;
                       i=i-n;
                   }
                else if(str[i-n]!=line[n])
                    break;
            }
            x=0;
        }
        }

        else if(e==1)
        {
            if(str[i]==lin[0])
        {
            for(n=0;n<c;n++)
            {
                if(str[i-n]==lin[n])
                    x++;
                if(x==c)
                   {
                        e++;
                        i=i-n;
                   }
                else if(str[i-n]!=lin[n])
                    break;
            }
            x=0;
        }
        }
    }
    //cout<<e;

    if(d==2&&e==2)
        cout<<"both";
    else if(d==2)
        cout<<"forward";
    else if(e==2)
        cout<<"backward";
    else
    cout<<"fantasy";




}
