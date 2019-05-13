#include<iostream>

using namespace std;

int main()
{
     long long int n,k,x;

    cin>>n>>k>>x;

    long long int a=0,b=0,c,maxx=0,i,d,arr[n+1],pos;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(i==0)
        {
            maxx=arr[i];
            pos=i;
        }
        else if(maxx<arr[i])
        {
            maxx=arr[i];
            pos=i;
        }

    }


    while(k>0)
    {
        b=maxx*x;
        maxx=max(b,maxx);
        k--;
    }
    arr[pos]=maxx;


    for(i=0;i<n;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            a+=arr[i];
        }

    }

    cout<<a;


}
