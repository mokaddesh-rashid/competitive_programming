#include<iostream>

using namespace std;

int main()
{
    long long int n,m;

    cin>>n>>m;

    m--;

    long long int arr[n+1],save[n+1],i,x=0,a,b,c,minn,pos;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        x+=arr[i];
        save[i]=x;
    }
     for(i=0;i<n;i++)
     {
         if(i==0)
         {
             minn=save[i+m];
             pos=i+1;

         }
         else
         {
             x=save[i+m]-save[i-1];

             if(minn>x)
             {
                 minn=x;
                 pos=i+1;
             }
         }
         if(i+m==n)
            break;


     }

     cout<<pos;


}
