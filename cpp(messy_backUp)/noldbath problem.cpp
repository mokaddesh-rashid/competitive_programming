#include<iostream>

using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int i,x,ar[n],a=0,d=3,z=0;

    ar[0]=1;
    ar[1]=2;
    ar[2]=3;

    for(i=2;i<n;i++)
        for(x=2;x<i;x++)
    {
        if(i%x==0)
            break;
        else if(x==i/2)
        {
            ar[d]=i;
            d++;
        }
    }
    for(i=0;i<d-2;i++)
    {
      z=ar[i]+ar[i+1]+1;
         for(x=0;x<d;x++)
         {
             if(z==ar[x])
             {
                 a++;
             }
         }


    }

    if(a>=k)
        cout<<"YES";
    else
        cout<<"NO";
}
