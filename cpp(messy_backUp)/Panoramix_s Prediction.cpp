#include<iostream>

using namespace std;

int main()
{
    int pos[100]={0},x=2,a=0,b,c,i;

    while(x<50)
    {
        if(pos[x]==0)
        {
            b=2;
            a=x*b;
            while(a<=50)
            {
               pos[a]++;
               b++;
               a=x*b;
            }
        }
        x++;
    }

    int n,m;

   cin>>n>>m;

   for(i=n+1;i<50;i++)
   {
       if(pos[i]==0)
       {
           a=i;
           break;
       }
   }

  // cout<<a<<endl;

   if(a==m)
    cout<<"YES";

   else
    cout<<"NO";
}
