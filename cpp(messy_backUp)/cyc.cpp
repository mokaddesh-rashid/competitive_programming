
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


   while(a!=b)
   {
     if(a!=b)
      x+=dis[a];
       cout<<x<<endl<<a<<endl;
     a++;

     if(a==n-1)
        a=0;


   }

    a=s;
    b=t;

    while(a!=b)
   {
      a--;
      if(a==-1)
        a=n-1;
      y+=dis[a];
       cout<<y<<endl<<a<<endl;
   }

   cout<<x<<endl<<y<<endl;
   cout<<min(x,y);

}
