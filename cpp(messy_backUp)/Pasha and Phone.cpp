#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int i,x=0,n,a,b,c,j,m,t,y=1,k=1,v,z,d;

    cin>>m>>t;

    m/=t;

    long long int arr[m+1],hmm[m+1];

    c=(long long)1000000007;

    for(i=0;i<m;i++)
    {
        cin>>arr[i];
    }
     for(i=0;i<m;i++)
    {
        cin>>hmm[i];
    }
    while(t>0)
    {
        k*=10;
        t--;
    }
    v=k/10;




    i=0;
    while(m>0)
    {
        n=arr[i];
        a=hmm[i];

        if(k==10)
        {

        b=0;
        x=0;


         while(b<k)
    {

        if(b!=a)
            x++;
        b+=n;
    }
        }


        else
        {
            if(a==0)
            {
                x=(k-1)/n-(k/10-1)/n;
            }

             else
             {
                  x=(k-1)/n;
                  x++;
             }

       // cout<<n<<' '<<k<<' '<<x<<endl;

        b=a*v;
        d=(a+1)*v;
        t=0;

        z=(b-1)/n;
        t=(d-1)/n;
          // cout<<b<<' '<<d<<' '<<endl;
         // cout<<z<<' '<<t<<' '<<endl;
         if(a!=0)
          x-=(t-z);


          //cout<<x<<endl;
        }
          y*=x;
          y=y%c;


         m--;
         i++;
    }



    cout<<y;
}
