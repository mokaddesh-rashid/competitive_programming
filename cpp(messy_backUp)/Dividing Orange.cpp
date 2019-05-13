#include<iostream>

using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int arr[n*k+2],use[99999]={0},i,j,a,b,c,x=0,bal[n*k+2];

    for(i=0;i<k;i++)
    {
        cin>>arr[i];
        use[arr[i]]++;
    }

    for(i=1;i<=n*k;i++)
    {
        if(use[i]==0)
        {
            bal[x]=i;
            x++;
        }
    }

    x=0;

    for(i=0;i<k;i++)
    {
        cout<<arr[i]<<' ';
        for(j=0;j<n-1;j++)
        {
            cout<<bal[x]<<' ';
            x++;
        }
    }
}
