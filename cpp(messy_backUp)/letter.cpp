#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m,a=0,c=0,y=0,z=0;
    cin>>n>>m;

    char str[n+1][m+1],ch[m+1];
    int b=n,d=m,i,x;


    for(i=0;i<n;i++)
    {
        cin>>str[i];
    }



    for(i=0;i<n;i++)
    {

        for(x=0;x<m;x++)
        {
            if(str[i][x]=='.')
            {
                y++;
                if(y==m)
                {
                	a++;
                	y=0;
                }
            }
            else
                z=1;

        }
        if(z==1)
        break;
    }

    z=0;
    y=0;

    for(i=n-1;i>=0;i--)
    {
        for(x=0;x<m;x++)
        {
            if(str[i][x]=='.')
            {
                y++;
                if(y==m)
                {
                	b--;
                	y=0;
                }
            }
            else
               {
               	 z=1;
               	 break;
               }

        }
        if(z==1)
        break;
    }

    z=0;
    y=0;
    for(i=0;i<m;i++)
    {

        for(x=0;x<n;x++)
        {
            if(str[x][i]=='.')
            {
                y++;
                if(y==n)
                {
                	c++;
                	y=0;
                }
            }
            else
                {
                	z=1;
                	break;
                }

        }
        if(z==1)
        break;
    }

    z=0;
    y=0;

    for(i=m-1;i>=0;i--)
    {
        for(x=0;x<n;x++)
        {
            if(str[x][i]=='.')
            {
                y++;
                if(y==n)
                {
                	d--;
                	y=0;
                }
            }
            else
               {
                	z=1;
                	break;
               }

        }
        if(z==1)
        break;

    }
    //cout<<a<<b<<c<<d;
    for(i=a;i<b;i++)
    {
         for(x=c;x<d;x++)
    {
        cout<<str[i][x];
    }
    cout<<endl;
    }
}
