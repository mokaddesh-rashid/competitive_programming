#include<iostream>

using namespace std;


int main()
{
    int n;

    cin>>n;

    int a=2,b=3,c=5,arr[n+1],x=0,prime[10*10*10*10]={0},j,i;

     i=2;
    while(i<=n)
    {
        j=i+i;

       if(prime[i]==0)
        while(j<=n)
        {
            prime[j]=1;
            j+=i;
        }

        i++;
    }

     //for(int i=0;i<n;i++)
       // cout<<prime[i]<<' '<<i<<endl;

    //cout<<endl;

    for(i=2;i<n;i++)
    {
        a=n+1;

        if(prime[i]==0)
        {
            a=i;
            b=i;
        }
        while(a<=n)
    {
        arr[x]=a;
        a*=b;
        x++;
    }

    }

    for(int i=b+1;i<=n;i++)
        {
            if(prime[i]==0)
            {
                arr[x]=i;
                x++;
            }
        }

    cout<<x<<endl;




     for(int i=0;i<x;i++)
        {
           cout<<arr[i]<<' ';
        }





}
