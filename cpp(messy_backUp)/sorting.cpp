
#include<iostream>

using namespace std;

int main()
{
   int i,n,a[99],b;
   cin>>b;
    for(i=0;i<b;i++)
    cin>>a[i];
   for(i=0;i<b;i++)
   {
       for(n=i+1;n<b;n++)
       {
           if(a[i]<a[n])
            swap(a[i],a[n]);
       }
   }
   for(i=0;i<b;i++)
    cout<<a[i];

}
