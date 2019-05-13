#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned  long long int t,k,n,i,j,a,b=0,c=0,d,arr[92],fact[10*10*10*10+2],maxx=pow(10,8);


    for(i=2;i<20;i++)
    {
        j=i;
        a=1;
        while(j>0)
        {
            a=a*j;
            j--;
        }
        arr[b]=a;
        b++;
    }



    t=pow(2,b);

    cout<<t<<endl;

    for(i = 1; i < t; i++) // start from 1
    {
        d=1;
         //cout<<'h';
        for(k = 0; k < b; k++)
        {
            if(i & (1 << k))
               {
                    d*=arr[k];

               }

        }

        if(d<maxx)
            c++;


    }

    cout<<c<<endl;

    return 0;
}
