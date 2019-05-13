#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,d;

    cin>>n>>d;

    int arr[n+1],x=0,y=0,a,b,c,m;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    cin>>m;

    for(int i=0;i<m;i++)
    {
       if(i<n)
        x+=arr[i];
       else
        y+=d;
    }

    cout<<x-y;

}
