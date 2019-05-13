#include<iostream>
#include<string>


using namespace std;

int main()
{
   int t;

   cin>>t;

   while(t>0)
   {
        int n;

        cin>>n;

        int arr[n+1],maxx=-1,i,j,a=0,b,c;

        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            maxx=max(arr[i],maxx);
        }

        b=100-maxx;

       for(i=0;i<n;i++)
        {
            if(arr[i]+b>=50)
                a++;
        }

        cout<<a<<endl;





    t--;
   }



}
