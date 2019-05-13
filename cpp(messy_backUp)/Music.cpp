#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,s,q;

    cin>>t>>s>>q;

    int a,b,c,x=0,y=0,z=0,i,down,sec=0,d=0,ans=0;
    double in,k;

    down=s;
    k=q;
    in=(k-1)/k;
    k=in;

    //cout<<in<<endl;


    while(down<t)
    {

          sec++;

         if(x==0)
         {
            in=s+k;
            x=1;
         }
         else
           in+=k;


         down=in;

         //cout<<sec<<' '<<down<<' '<<in<<endl;

        if(sec>down)
        {
            sec=1;
            ans++;
        }


    }

    cout<<ans+1;

}
