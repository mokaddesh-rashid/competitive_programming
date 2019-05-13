#include<iostream>

using namespace std;

int main()
{
    int ar[4],i,x=0,a=-1,b,n;

    for(i=0;i<4;i++)
    {
        cin>>ar[i];
    }

    for(i=0;i<4;i++)
    {
        for(n=0;n<4;n++)
        {
            if(i==n)
                continue;
           else  if(ar[i]==ar[n])
            {
                ar[n]=a;
                x++;
                a--;
            }
        }
    }

    cout<<x;
}
