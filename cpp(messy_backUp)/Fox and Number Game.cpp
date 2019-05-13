#include<iostream>

using namespace std;

int main()
{
   int n_x;

   cin>>n_x;

   int value[n_x+1],i,n,a=1,b,c,x=0,minn,maxx;

   for(i=0;i<n_x;i++)
   {
       cin>>value[i];

       if(i==0)
       {
           minn=value[i];
       }
       else
        minn=min(value[i],minn);
   }

   while(a!=0)
   {
       a=0;
       b=minn;

    for(i=0;i<n_x;i++)
    {
      if(value[i]>b)
      {
          value[i]-=b;
          minn=min(minn,value[i]);
          a=1;
      }
    }

   }

   for(i=0;i<n_x;i++)
      x+=value[i];


   cout<<x;


}
