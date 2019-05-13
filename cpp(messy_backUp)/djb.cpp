#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
   int n;

   cin>>n;

   long long int x[n+1],y[n+1],max_x,min_x,max_y,min_y,i,a,b;

   for(i=0;i<n;i++)
   {
       cin>>x[i]>>y[i];

       if(i==0)
       {
           max_x=x[i];
           min_x=x[i];
       }

       else
       {
           max_x=max(max_x,x[i]);
           min_x=min(min_x,x[i]);
       }

        if(i==0)
       {
           max_y=y[i];
           min_y=y[i];
       }

       else
       {
           max_y=max(max_y,y[i]);
           min_y=min(min_y,y[i]);
       }
   }

   a=max(max_x-min_x,max_y-min_y);

  cout<<a*a;
}

