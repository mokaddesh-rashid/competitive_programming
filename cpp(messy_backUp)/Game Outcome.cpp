#include<iostream>


using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1][n+1],up[n+1],low[n+1],i,x,a=0;


    for(i=0;i<n;i++)
        for(x=0;x<n;x++)
    {
        cin>>arr[i][x];
    }

    for(i=0;i<n;i++)
   {
       a=0;
            for(x=0;x<n;x++)
    {
        a+=arr[i][x];
    }

      low[i]=a;
   }

    for(i=0;i<n;i++)
   {
       a=0;
            for(x=0;x<n;x++)
    {
        a+=arr[x][i];
    }

      up[i]=a;
   }

   a=0;

   for(i=0;i<n;i++)
   {
       for(x=0;x<n;x++)
       {
           if(up[i]>low[x])
            a++;
       }
   }

   cout<<a;




}
