#include<iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;

    cin>>n;

    int fac[n+1],i,a,b,c=0,x,y;

    for(i=0;i<n;i++)
    {
        cin>>fac[i];
    }
    int d;

    d=n;
    for(i=0;i<n;i++,d--)
    {
        for(x=i;x<d;x++)
        {
            if(fac[x]<fac[i])
                swap(fac[x],fac[i]);
            if(fac[d-1]<fac[x])
                swap(fac[d-1],fac[x]);
        }
    }

    d=fac[0];
     if(fac[0]==fac[n-1])
     {
         for(i=0;i<n;i++)
         {
             c=c+i;
         }
     }

    else
    for(i=0;i<n;i++)
    {
        y=0;
        a=fac[i];
        b=1;
        if(fac[i]==fac[i-1])
          a=fac[i-2]+1;


        while(b==1)
        {
            b=0;
            for(x=0;x<n;x++)
            {
                if(i==x)
                    continue;
                else if(fac[x]==a)
                    {
                        b=1;
                        break;
                    }

            }
            if(b==1&&y==0)
              {
                if(d>a)
                  a=d;
                else
                    d=a;

                  y=1;
              }
            else if(b==1)
            {
                d++;
                a++;
            }
        }


       // cout<<a<<' '<<fac[i]<<endl;
        c=c+(a-fac[i]);
        fac[i]=a;

    }

    cout<<c;
}
