#include<iostream>

using namespace std;

int main()
{
    int n,i,x,y;

    cin>>n;

    int pos[n+2];

    for(i=0;i<n;i++)
    {
        pos[i]=i+1;
    }

   if(n==1||n==2)
    cout<<1<<endl<<1;
   else if(n==3)
    cout<<2<<endl<<1<<' '<<3;

   else
   {
    x=n/2;
    y=n-1;

    cout<<n<<endl;

    cout<<pos[x]<<' ';

    for(i=0;i<x-1;i++,y--)
    {
        cout<<pos[i]<<' '<<pos[y]<<' ';
    }


    cout<<pos[x-1]<<' ';

     if(n%2)
        cout<<pos[x+1]<<' ';
   }
}
