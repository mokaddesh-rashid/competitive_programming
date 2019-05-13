#include<iostream>
#include<string>


using namespace std;


int main()
{
    string str,st,k;

    int n,t,a,o=0;

    cin>>n>>t;

    cin>>str;
    cin>>st;

    k=str;

    int x,i,j,y;

    x=n-t;
    y=n-t;

    for(i=0;i<str.size();i++)
    {
        if(str[i]==st[i]&&x>0&&y>0)
        {
            k[i]=str[i];
             x--;
             y--;
             o++;
        }

    }


    for(i=0;i<str.size();i++)
    {
        if(str[i]==st[i]&&o>0)
        {
           o--;
        }
        else if(x>=y&&x>0&&str[i]!=st[i])
       {
           k[i]=str[i];
           x--;
       }
       else if(x<y&&y>0&&str[i]!=st[i])
       {
           k[i]=st[i];
           y--;
       }
       else
       {

         a=max(str[i]-st[i],st[i]-str[i]);

         if(a==0&&str[i]=='z')
              k[i]=str[i]-1;
         else if(a==0)
              k[i]=str[i]+1;
         else if(a==1&&(str[i]=='z'||str[i]=='y'||str[i]=='x'))
              k[i]=str[i]-3;
         else if(a==1)
              k[i]=str[i]+3;
         else if(str[i]=='z')
              k[i]=str[i]-1;
         else
            k[i]=++str[i];
          //cout<<i<<' '<<a<<' '<<<<endl;
       }
    }

    if(x==0&&y==0)
           cout<<k;

    else
          cout<<-1;
}
