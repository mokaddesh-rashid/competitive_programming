#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+3],i,x=0,a=0;

    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    for(i=0;i<n;i++)
       {
           if(arr[i]==arr[i+1]&&arr[i]!=0)
            x++;

           if(arr[i]==arr[i+1]&&arr[i]==arr[i+2]&&arr[i]!=0)
             a=1;
       }

    if(a==1)
        cout<<-1;
    else
        cout<<x;







}
