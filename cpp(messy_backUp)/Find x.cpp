#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,x;

    cin>>n>>x;

    int arr[n+1],a=0,b=n-1,c=0,d,i;

    for(i=0;i<n;i++)
       {
            cin>>arr[i];
            if(x==arr[i])
                c++;
       }

    sort(arr,arr+n);


    while(a<b)
    {
        if(arr[a]+arr[b]==x)
        {
            cout<<arr[a]<<' '<<arr[b]<<endl;
            a++;
            b--;
            c++;

        }
        else if(arr[a]+arr[b]>x)
        {
            b--;
        }
        else if(arr[a]+arr[b]<x)
        {
            a++;
        }
    }
}
