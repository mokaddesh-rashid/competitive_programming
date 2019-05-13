#include<iostream>
#include<string>


using namespace std;

int main()
{
   int t;

   cin>>t;

   while(t>0)
   {
        string str,st;
        int n,arr[200]={0},i,j,a=0,b,c;

        cin>>n;

        cin>>str;

        for(i=0;i<n;i++)
        {
             if(str[i]=='*'&&i==0)
            {
                arr[i]=1;
                arr[i+1]=1;
            }
            else if(str[i]=='*')
            {
                arr[i-1]=1;
                arr[i]=1;
                arr[i+1]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
               // cout<<i<<endl;
                arr[i]=1;
                arr[i+1]=1;
                arr[i+2]=1;
                a++;
            }
        }

        cout<<a<<endl;





    t--;
   }



}
