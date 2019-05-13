#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
   int n;

   cin>>n;

   int arr[n+1],i,x=0,a=0,b,c;
   double y;

   for(i=0;i<n;i++)
   {
       cin>>arr[i];
   }


   sort(arr,arr+n);


   for(i=n-1;i>=0;i--,a++)
   {
       //cout<<"H";
       if(a%2==0)
        x+=(arr[i]*arr[i]);
       else
        x-=(arr[i]*arr[i]);

   }


   y=x;

   printf("%.4lf",3.1416*y);
}
