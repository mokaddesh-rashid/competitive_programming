#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    char str[n+1],ch='1';
    int i,x=0,a=1,z=0,b=0,y=-1;

    cin>>str;

    while(str[n]!='1')
    {
        n--;
    }
    while(str[a]!='1')
    {
        z++;
    }
    for(i=z;i<n;i++)
   {
       while(str[i]=='1')
       {
           b++;
       }
   }

    for(i=z;i<n;i++)
   {
       y=0;
       if(str[i]=='1'&&str[i+1]=='0')
       {
           while(str[i+1]!='1')
           {
               y++;
               i++;
           }
          // break;
       }
       if(y!=x)
       {
           a=0;
           break;
       }
   }



    if(a==1)
        cout<<"YES";
    else
        cout<<"NO";



}
