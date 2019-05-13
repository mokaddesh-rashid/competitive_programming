#include<iostream>
#include<string>


using namespace std;

int main()
{
   string str,st;

   cin>>str>>st;


   long long int a=0,i,j,x=0,y=0,b=0,c=0,arr[str.size()+1],brr[str.size()+1],d=0,t;


   for(i=0;i<str.size();i++)
   {
       a+=str[i];
       arr[i]=a;
       b+=st[i];
       brr[i]=b;
   }

   x=str.size()/2-1;
   a=arr[x];
   b=arr[str.size()-1]-a;

   c=brr[x];
   d=brr[str.size()-1]-c;

   if(a==c&&b==d)
      {
          t=1;

          int chk_a[27]={0},chk_b[27]={0},chk_c[27]={0},chk_d[27]={0};

          for(i=0;i<=x;i++)
          {
              chk_a[str[i]-97]++;
              chk_c[st[i]-97]++;
          }

          for(i=0;i<27;i++)
          {
              if(chk_a[i]!=chk_c[i])
                t=0;
          }

          for(i=0;i+x+1<str.size();i++)
          {
              chk_b[str[i+x+1]-97]++;
              chk_d[st[i+x+1]-97]++;
          }

          for(i=0;i<27;i++)
          {
              if(chk_b[i]!=chk_d[i])
                t=0;
          }


      }
   if(a==d&&b==c)
      {
          t=1;

          int chk_a[27]={0},chk_b[27]={0},chk_c[27]={0},chk_d[27]={0};

          for(i=0;i<=x;i++)
          {
              chk_a[str[i]-97]++;
              chk_d[st[i+x+1]-97]++;

          }

          for(i=0;i<27;i++)
          {
              if(chk_a[i]!=chk_d[i])
                t=0;
          }

          for(i=0;i+x+1<str.size();i++)
          {
              chk_b[str[i+x+1]-97]++;
              chk_c[st[i]-97]++;

          }

          for(i=0;i<27;i++)
          {
              if(chk_b[i]!=chk_c[i])
                t=0;
          }
      }


   if(str==st||t==1)
      cout<<"YES";
   else
      cout<<"NO";





}
