#include<iostream>

using namespace std;

int main()
{
    int n,k,i=0;

    cin>>n>>k;

    int a=1,b=n,count0=1,k_time=k;

    cout<<a<<' ';
    a++;



    while(count0<n)
    {

        if(k==1&&i%2==0)
        {
           while(a<=b)
           {

            cout<<a<<' ';
            a++;
            count0++;

           }
        }

        else if(k==1&&i%2==1)
        {
           while(b>=a)
           {

            cout<<b<<' ';
            b--;
            count0++;

           }
        }
        else if(i%2==0)
       {
           cout<<b<<' ';
           b--;
           count0++;
           k--;

       }

       else if(i%2==1)
       {

           cout<<a<<' ';
           a++;
           count0++;
           k--;

       }

       i++;

    }
}
