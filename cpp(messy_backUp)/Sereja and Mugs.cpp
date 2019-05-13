#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,s;

    cin>>n>>s;

    int maxx=-1,arr[n+1],i,j,x=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        x+=arr[i];
        maxx=max(arr[i],maxx);
    }

    if(x-maxx<=s)
        cout<<"YES";

    else
        cout<<"NO";
}
