#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a=0,b=0,c=0,d=1;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(arr[i]>=arr[i-1]&&c==0)
            c=i-1;
        else if(arr[i]<arr[i-1])
            c=0;

        if(arr[0]>=arr[n-1]&&i==n-1&&a==0&&arr[i]<arr[i-1])
            d=0;

        else if(arr[i]<arr[i-1]&&i!=0)
            a=1;
        if(arr[i]>arr[i-1]&&i!=0)
            b=1;
    }
    //cout<<c<<endl;

    if(d==0)
        cout<<1;

    else if(a==0)
        cout<<0;
    else if(b==0)
        cout<<-1;
    else if(c==0)
        cout<<-1;

    else
    {
       a=0;

        for(i=0;i<c;i++)
        {
          if(arr[i]<arr[i-1]&&i!=0)
            a=1;

          if(arr[i]<arr[n-1])
            a=1;
        }

       if(a==0)
        cout<<n-c;

     else
        cout<<-1;
    }
}
