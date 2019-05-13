#include<iostream>
#include<cmath>


using namespace std;


int main()
{
    long long int x,a=1;

    cin>>x;

   while(x!=1)
   {
       if(x%2)
       {
           x--;
           a++;
       }
       else
       {
           x/=2;
       }

   }

   cout<<a;
}



