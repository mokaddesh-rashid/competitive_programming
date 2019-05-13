#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],i=0,j,x=7,a=0,b=0,c;


   while(x<=n)
   {
       //cout<<7;
       arr[i]=7;

       x+=7;
       i++;
   }
  // cout<<endl;
   x-=7;
   if(x==n)
   {
       a=1;
       x=i-1;
   }
   if(x!=n)
   {
       arr[i]=n-x;
       x=i;
   }

   b=-1;
   c=0;

   if(a!=1)
   for(j=i;j>=0;j--)
   {

       c+=arr[j];
      // cout<<c<<endl;
       if(c%4==0)
       {
           b=c/4;
           a=2;
           break;
       }
   }
   if(a!=1&&a!=2&&n%4!=0)
     cout<<-1;
   else if(a!=1&&a!=2&&n%4==0)
    {
       x=0;
       while(x<n)
   {
      cout<<4<<endl;
      x+=4;

   }

   }


    else
   {
       x=0;
    i=0;
  while(x<n)
   {
       if(i<b&&a==2)
        {
            cout<<4;
            x+=4;
        }
       else
        {
            cout<<7;
            x+=7;
        }
        i++;

   }
   }



}
