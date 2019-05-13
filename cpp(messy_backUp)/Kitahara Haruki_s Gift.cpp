#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],use[105]={0},i,x=0,a=0,b=0,c;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        x+=arr[i];

    }

    if(x%200)
        cout<<"NO";

    else
    {
       c=x/2;
       i=0;

       while(a<c&&i<n)
       {
          if(a+arr[i]<=c)
            a+=arr[i];
          i++;
       }

       if(a==c)
          cout<<"YES";
       else
        cout<<"NO";
    }




}

