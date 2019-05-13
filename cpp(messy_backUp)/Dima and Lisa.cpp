#include<iostream>

using namespace std;

int main()
{
    long long int x,n,a=0,b=-1,c=-1,i,d=-1,arr[333]={0},prime[300],y=0,j,z,t=0;

    cin>>n;

    x=n;
    z=n;

    while(a==0)
    {
        a=1;

        if(n%2==0)
            a=0;
        else if(n%3==0)
            a=0;
        else
        {
            i=5;
            while(i*i<=n)
            {
               if(n%i==0||n%(i+2)==0)
                    a=0;
               i+=6;
            }
        }

        if(a==0)
            n--;
    }

    b=n;

    x-=n;
    t++;

    for(i=2;i<300;i++)
    {
        j=i;

     if(arr[i]==0)
        while(j<300)
        {
            j+=i;

            if(j<=300)
               arr[j]=1;

        }
    }


    for(i=2;i<300;i++)
    {
        if(arr[i]==0)
        {
            if(i==x)
            {
                t++;
                c=x;
                x=0;
            }
            prime[y]=i;
            y++;
        }
    }


    i=0;
    j=y-1;


    while(i<=j)
    {
        if(prime[i]+prime[j]==x)
        {
            t+=2;
            c=prime[i];
            d=prime[j];
            break;
        }
        else if(prime[i]+prime[j]>x)
        {
            j--;
        }
        else if(prime[i]+prime[j]<x)
        {
            i++;
        }

    }

    if(z==3)
        cout<<1<<endl<<3;

   else
   {
       cout<<t<<endl;

    cout<<b<<' ';

   if(c!=-1)
    cout<<c<<' ';

   if(d!=-1)
    cout<<d;
   }






}
