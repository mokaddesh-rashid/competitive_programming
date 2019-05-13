#include<iostream>

using namespace std;

int main()
{
    long long int i,n,a=0,b=0,c=0,d=0,e,x;


    cin>>n;

    long long int arr[n+1];

   for(i=0;i<n;i++)
   {
       cin>>arr[i];


       if(arr[i]<arr[i-1]&&i>0)
       {
          // cout<<"here\n";
          e=i;
           i++;
          while(i<n)
          {
              cin>>arr[i];
              if(arr[i]>arr[i-1])
                 break;

                i++;
          }

          c++;
           //cout<<arr[a]<<' '<<arr[i]<<endl;
          if(arr[a]>arr[i])
            {
                swap(arr[a],arr[i]);
                c++;
            }

            b=a;
            a=i;
       }

   }

   if(c==0)
    cout<<"yes\n"<<1<<' '<<1;
   else if(c>1)
   cout<<"no";


   else
 {
       cout<<"yes\n"<<e<<' '<<a;
 }
}
