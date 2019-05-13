#include<iostream>
#include<string>

using namespace std;

int main()
{
    string n;

    long long int x,y;

    cin>>x>>y>>n;

    long long int i,a,b,arr[n+1];

    arr[0]=x;
    arr[1]=y;

     if(x!=0&&y!=0)
      for(i=2;i<n;i++)
    {
        arr[i]=arr[i-1]-arr[i-2];
    }

    if(x==0&&y==0)
        cout<<0;

    else if(arr[n-1]<0)
      cout<<1000000007-(arr[n-1]%1000000007)*-1;


    else
    cout<<arr[n-1]%1000000007;
}

