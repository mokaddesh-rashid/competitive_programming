#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,k,i=0;

    cin>>n;

    int a=1,b=2,count0=1,k_time=k;


   if(n%2==1)
    cout<<-1;

   else
   {
        while(count0<n)
    {


      cout<<max(a,b)<<' '<<min(a,b)<<' ';
      a+=2;
      b+=2;
      count0+=2;

    }

   }
}
