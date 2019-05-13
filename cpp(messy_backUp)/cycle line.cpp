#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int dis[n+1],i,x=0,y=0,a,b,c,s,t;

    for(i=0;i<n;i++)
        cin>>dis[i];

    cin>>s>>t;

    s--;
    t--;
    a=s;
    b=t;
   while(a!=t)
   {
       if(a!=t)
      x+=dis[a];

      if(a<t)
        a++;
      if(a>t)
        a--;


   }

    a=s;
    b=t;

   if(a<t)
   while(a!=t)
   {

     if(a!=t)
      y+=dis[a];
     // cout<<a<<' '<<y<<endl;

      a--;

      if(a==-1)
        a=n-1;


   }

    else if(a>t)
   while(a!=t)
   {
    if(a!=t)
      y+=dis[a];

      a++;

      if(a==n)
        a=0;


   }
   cout<<x<<endl<<y<<endl;
   cout<<min(x,y);

}
