
#include<iostream>

using namespace std;


int main()
{
    long long int n,m;

    cin>>n>>m;

    long long int arr[n+2],a,b,c,d,x=0,i;

    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<m;i++)
        {
            cin>>a>>b;
            x=x+min(arr[a],arr[b]);
        }

    cout<<x;
}
