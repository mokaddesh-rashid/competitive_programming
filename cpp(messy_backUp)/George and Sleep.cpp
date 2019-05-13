#include<iostream>

using namespace std;

int main()
{
   string str,str2;

   cin>>str>>str2;

   int a=0,b=0,c,d,x,y,z,x2,y2;

   x2=str[0]-48;
   x2*=10;
   x2=x2+(str[1]-48);

   y2=str[3]-48;
   y2*=10;
   y2=y2+(str[4]-48);

   x=str2[0]-48;
   x*=10;
   x=x+(str2[1]-48);

   y=str2[3]-48;
   y*=10;
   y=y+(str2[4]-48);

   if(y>y2)
    x=(x+1)%24;

    while(y!=y2)
   {
       b++;
       y=(y+1)%60;
   }


   while(x!=x2)
   {
       a++;
       x=(x+1)%24;
   }



   if(a<10)
    cout<<0<<a;
   else
    cout<<a;

   cout<<':';

   if(b<10)
    cout<<0<<b;
   else
    cout<<b;


}
