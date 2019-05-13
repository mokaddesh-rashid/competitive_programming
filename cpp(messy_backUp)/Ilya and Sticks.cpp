#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    int arr[n+1],i,j,x=0,a,b,c,d=-1;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    sort(arr,arr+n,greater<long long int>());


    for(i=3;i<n;i++)
    {
        if(arr[i]==arr[i-1]&&arr[i-2]==arr[i-3])
        {
            if(d==-1)
            {
                d=arr[i]*arr[i-2];
                x+=d;
                i+=3;
            }
            else if(d==arr[i]*arr[i-2])
            {
                x+=d;
                i+=3;
            }
        }
        if(arr[i]==arr[i-1]-1&&arr[i-2]==arr[i-3]-1)
        {
            if(d==-1)
            {
                d=arr[i]*arr[i-2];
                x+=d;
                i+=3;
            }
            else if(d==arr[i]*arr[i-2])
            {
                x+=d;
                i+=3;
            }
        }


    }

    cout<<x;




}
