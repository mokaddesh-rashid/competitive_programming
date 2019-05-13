#include<iostream>

using namespace std;

int main()
{
   int i,n,a[99],b,m=0,d;

   cin>>b;

    for(i=0;i<b;i++)
    cin>>a[i];

    d=b;

  for(i=0;i<b;i++,d--)
    for(n=i;n<d;n++)
  {
      if(a[i]>a[n])
        swap(a[i],a[n]);
      if(a[d-1]<a[n])
        swap(a[d-1],a[n]);
  }


   for(i=0;i<b;i++)
    cout<<a[i]<<' ';

}
