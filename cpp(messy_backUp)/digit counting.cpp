#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    long long int t,x=0;

//    cin>>t;

   // while(t>0)
    {
        int str;
      long long int a,num,x,y,n,count0=0,value=0,ans=0;

        cin>>a;

        n=a;

         while(n>0)
       {
           count0=count0+1;

        if(count0>1)
           value*=10;
        else
            value=1;

              n/=10;
          // cout<<n<<endl;

       }

       //cout<<count0<<endl<<value<<endl;

       x=a-value+1;
       ans=ans+(x*count0);
       a=value-1;
       count0--;
       value/=10;

       while(count0>0)
       {
        x=a-value+1;
        //cout<<x<<endl;
       ans=ans+(x*count0);
       a=value-1;
       count0--;
       value/=10;
       }

       cout<<ans<<endl;

      // cout<<x<<endl;



       // while(a>0)
        {


        }



       // t--;
    }
   // cout<<x;

}
