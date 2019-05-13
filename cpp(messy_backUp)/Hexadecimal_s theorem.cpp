#include<iostream>

using namespace std;

int main()
{
    long long int a=0,b=0,c=0,d=0,n,i,x=0;

    cin >> n;

     long long int arr[11111];

     arr[0]=0;
     arr[1]=1;

     i=2;

     while(arr[i-1]+arr[i-2]<n)
     {
         arr[i]=arr[i-1]+arr[i-2];

         i++;
     }

     i--;

    // cout<<arr[i]<<endl;

     while(x<n&&i>=0)
     {
         if(x+arr[i]<=n)
         {
             if(d==0)
             {
                 a=arr[i];
                 x+=arr[i];
                 d++;
             }
             else if(d==1)
             {
                 b=arr[i];
                  x+=arr[i];
                 d++;
             }
             else if(d==2)
             {
                 c=arr[i];
                 x+=arr[i];
                 d++;
             }
         }
         else
            i--;
     }

     cout<<a<<' '<<b<<' '<<c;




}
