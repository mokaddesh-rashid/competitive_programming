#include<iostream>

using namespace std;

int main()
{
   int mark[2001]={0},i,x,a,b,c=1,n,value[2001],output[2001]={0};

   cin >> n;


   for(i=0;i<n;i++)
   {

       cin>>a;

       value[i]=a;
       mark[a]++;

   }
   a=2000;
   while(a>0)
   {
       if(mark[a]!=0)
       {
           x=0;
          for(i=0;i<n;i++)
          {
              if(a==value[i])
              {
                  output[i]=c;
                  x++;
              }
          }
          c+=x;
       }
       a--;
   }

   for(i=0;i<n;i++)
      cout<<output[i]<<' ';

}
