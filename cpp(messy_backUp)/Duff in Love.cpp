#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;


int main()
{
    long long int n,x;

    cin>>n;

     x=sqrt(n);

    long long int i,a,b,y=0,c,d,stac[x*2+2],div[x*2+2],top=-1,k,j,ans=1;




    for(i=2;i<=x+1;i++)
    {
       if(n%i==0)
       {




          a=i;
          b=n/i;
          c=sqrt(a);
          d=sqrt(b);
          //cout<<a<<' '<<b<<endl;

          if(c*c==a)
          {
             // cout<<c<<' ';
              top++;
              stac[top]=a;
          }
          if(d*d==b)
          {
              top++;
              stac[top]=b;
          }

          div[y]=a;
          y++;
          div[y]=b;
          y++;

       }

    }
    div[y]=n;
    y++;

   // cout<<endl<<y<<endl;



    for(i=0;i<y;i++)
    {
        //cout<<div[i]<<' ';
        k=0;
        a=div[i];
        b=sqrt(a);

        for(j=0;j<=top;j++)
              {
                  if(a%stac[j]==0)
                    {
                        k=1;
                        break;
                    }
              }


        if(k==0&&b*b!=a)
           {
                ans=max(a,ans);

           }
    }
    //cout<<endl;


    if(n==2)
        ans=2;
    cout<<ans;



}
