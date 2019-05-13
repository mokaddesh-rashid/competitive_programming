#include<iostream>

using namespace std;

int main()
{
   int n;

   cin>>n;

   int value[n+1],from[n+1],to[n+1],s_time=0,i,x,a,b,minn,pos;

   for(i=0;i<n;i++)
   {
       cin>>value[i];
   }

   for(i=0;i<n;i++)
  {
        for(x=i;x<n;x++)
   {
       if(x==i)
        minn=value[x];

       else if(minn>value[x])
       {
          minn=value[x];
          pos=x;

       }
   }

   if(minn!=value[i])
   {
       from[s_time]=i;
       to[s_time]=pos;
       swap(value[i],value[pos]);
       s_time++;
   }

  }

  cout<<s_time<<endl;

  for(i=0;i<s_time;i++)
    cout<<from[i]<<' '<<to[i]<<endl;

}
