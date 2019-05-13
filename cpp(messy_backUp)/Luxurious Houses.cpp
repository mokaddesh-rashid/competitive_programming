#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int arr[n+1],i,x,a,maxx=-1,save[n+1],j=0;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=n-1;i>=0;i--,j++)
    {
        a=arr[i];
        if(arr[i]>maxx)
           {
                save[i]=0;
                maxx=arr[i];
           }
        else
        {
           save[i]=maxx+1-arr[i];
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<save[i]<<' ';
    }
}
