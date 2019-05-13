#include<iostream>
#include<cstring>


using namespace std;


int main()
{
    int z,o;

    cin>>z>>o;

    int i,j,k,x,y,a=0,b=0;

    x=z+o;
    y=x/3;



    if(z>o+1||z<y)
        cout<<-1;

     else
     {
         for(i=0;i<x;i++)
         {
           if(o>=z&&a<2)
           {
               cout<<1;
               o--;
               a++;
           }
           else
           {
               cout<<0;
               z--;
               a=0;
           }
         }
     }




}
