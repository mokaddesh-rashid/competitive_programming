#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],cmp[n+1],i,x=0,a,b,c=0,p;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        cmp[i]=arr[i];

    }

    sort(arr,arr+n);

    for(i=0;i<n;i++)
    {

        if(cmp[i]!=arr[i])
            x++;

    }





    if(x<=2)
        cout<<"YES";
    else
        cout<<"NO";
}
