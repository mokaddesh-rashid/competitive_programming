#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[1111];
    char ch;
    int k;

    cin>>str;
    cin>>k;

    int i,n,a=0,b=0,c,x,y=0,z=0,m=0,j=0,len;

    for(i=0;i<strlen(str);i)
    {

       char *check=new char[1111];
       ch=str[i];

       for(n=i+1;n<strlen(str);n++)
       {
           if(ch==str[n])
             {
                  x=n;
                  break;
             }
            else if(n==strlen(str)-1)
                b=1;
       }
       y=x;
      // cout<<x<<endl;
       if(b==1)
        break;
        a=i;
       for(n=x;n>=i;n--)
       {
           if(str[a]!=str[n])
                break;

           a++;

           if(a==x)
           {

               len=x+1-i;
               if(z==0)
                {
                    z++;
                    j=len;
                    m=m+len;
                }
               else if(j==len||z==0)
                   {
                       z++;
                     if(z!=0)
                      m=m+len;
                   }
               i=x+1;


           }



       }
        //cout<<m<<endl;
        if(x==strlen(str)-1)
            break;




    }

   if(z==k&&m==strlen(str))
       cout<<"YES";
   else
       cout<<"NO";
}
