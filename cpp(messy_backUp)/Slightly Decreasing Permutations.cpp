#include<iostream>

using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int i,b,c,d,f,x,a,y;

   if(k!=0&&k!=n-1)
   {
        x=n/k;
    a=1;
    b=0;
    c=n;

    y=0;
    while(y<k)
    {
        if(y%2==0)
        {
            d=x;
            while(d>0)
            {
                cout<<a<<' ';
                a++;
                d--;
            }

            y++;

        }
        else if(y%2)
        {
            d=x;
            while(d>0||k-1==y)
            {
                cout<<c<<' ';
                c--;
                d--;
                if(c==a-1)
                    break;
            }




            y++;
        }
    }

   }

   else if(k==0)
    for(i=1;i<=n;i++)
      cout<<i<<' ';

   else if(k==n-1)
    for(i=n;i>0;i--)
      cout<<i<<' ';

}
