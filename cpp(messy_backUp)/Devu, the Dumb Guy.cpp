#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n,m;

    cin>>n>>m;

    long long int arr[n+1],i,x,ans=0;

    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    for(i=0;i<n;i++)
    {
        ans=ans+(arr[i]*m);

        if(m>1)
            m--;
    }
    cout<<ans;
}
