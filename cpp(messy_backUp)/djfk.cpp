#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int n,l,r,x=1,i,a=1,b,c;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>l>>r;

       x=log(r+2)/log(2);
      // cout<<x<<endl;

       x=pow(2,x)-1;
       // cout<<x<<endl;

       if(x>=l&&x<=r)
          cout<<x<<endl;

       else
       {
           cout<<"her";
          long long int p,maxx=-1;

         while(l<=r)
         {
             b=l;
             c=0;
             while(b>0)
             {
               c=c+(b%2);
               b/=2;
             }

             if(c==a)
             {
               p=l;
               break;
             }
             else if(maxx<c)
             {
                 p=l;
                 maxx=c;
             }
             if(l%2)
                l+=2;
             else
                l++;
         }

         cout<<p<<endl;
       }


    }
}
