#include<iostream>
#include<cstring>

using namespace std;

int main()
{
   int n;

   cin>>n;

   char str[n+1][n+1];

   int f,employe[111]={0},egor[n+1],i,x,a=0,b=0,c=0,d=0;

   for(i=0;i<n;i++)
   {
       cin>>str[i];

       for(x=0;x<strlen(str[i]);x++)
       {
          if(str[i][x]=='1')
            employe[x]++;
       }
   }

   for(i=0;i<n;i++)
   {
       cin>>egor[i];


       if(egor[i]!=employe[i])
         c++;
   }

   if(c!=0)
  {
       cout<<c<<endl;

   for(i=0;i<n;i++)
   {

       if(egor[i]!=employe[i])
        cout<<i+1<<' ';
   }
  }

   else
   {

   while(d<n&&c==0)
   {
            for(i=0;i<n;i++)
   {
        if(i==d)
            continue;

        else
          for(x=0;x<strlen(str[i]);x++)
           {

          if(str[i][x]=='1')
            employe[x]++;
           }
   }

   for(i=0;i<n;i++)
   {
       if(egor[i]!=employe[i])
         c++;
   }

   if(c!=0)
  {
       cout<<c<<endl;

   for(i=0;i<n;i++)
   {

       if(egor[i]!=employe[i])
        cout<<i+1<<' ';
   }
  }
   d++;
   }


   }


   if(c==0)
    cout<<0;


}
