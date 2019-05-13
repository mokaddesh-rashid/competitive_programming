#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int t,i;
    cin>>t;

    char str[10000];

    int x,len,y,z=0,n,a,b;

     for(i=0;i<t;i++)
     {
         cin>>x>>str;
         b=0;
          z=0;
         for(n=0;n<x+1;n++)
         {
            y=str[n]-48;

             if(z>=n)
                z+=y;

             else if(y==0)
                continue;
             if(n==x&&z<n)
             {
                 a=x-z;
                 z+=a;
                 b+=a;
             }
             else if(z<n)
             {
                 a=n-z;
                 z+=a;
                 z+=y;
                 b+=a;
             }


         }
        cout<<"Case"<<' '<<'#'<<i+1<<':'<<' '<<b<<endl;
         //cout<<b;



     }


}
