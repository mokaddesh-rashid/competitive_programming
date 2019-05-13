#include<iostream>

using namespace std;

int main()
{
    int x,y,a,b;

    cin>>x>>y>>a>>b;

    int i,j,c,d,z=0,arr[x*y],t;

    t=a;

   while(t<=x)
   {
    c=t;
    d=b;

    while(d<c&&d<=y)
    {
        if(c>d&&d<=y)
        {
            //cout<<c<<' '<<d<<endl;
            arr[z]=c;
            z++;
            arr[z]=d;
            z++;

            d++;
        }
    }

    t++;
   }

   cout<<z/2<<endl;

   for(i=0;i<z;i+=2)
      cout<<arr[i]<<' '<<arr[i+1]<<endl;


}
