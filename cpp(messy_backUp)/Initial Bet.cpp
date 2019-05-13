#include<iostream>

using namespace std;

int main()
{
   int c[12],i,x=0,a=0,b;

   for(i=0;i<5;i++)
   {
       cin>>c[i];
       x=min(x,c[i]);
       a+=c[i];
   }


 if(c[0]==c[1]&&c[2]==c[3]&&c[4]==c[0]&&c[2]==c[4]&&c[0]==0)
    cout<<-1;
 else if(c[0]==c[1]&&c[2]==c[3]&&c[4]==c[0]&&c[2]==c[4])
    cout<<c[0];
  else if(a%5==0)
    cout<<(a/5)-x;
 else
    cout<<-1;

}
