#include<iostream>

using namespace std;

int main()
{
    int n,i,x,a,b;

    cin>>n;


   if(n%2==0)
    cout<<n*(n/2)<<endl;

   if(n%2==1)
   {
      a=n/2+1;
      b=n/2;

      a=(a*a)+(b*b);

      cout<<a<<endl;
   }

    for(i=0;i<n;i++)
    {
        for(x=0;x<n;x++)
        {
            if(i%2==0)
            {
                if(x%2==0)
                    cout<<'C';
                else
                    cout<<'.';
            }
            if(i%2==1)
            {
                if(x%2==1)
                    cout<<'C';
                else
                    cout<<'.';
            }

        }
         cout<<endl;
    }
}
