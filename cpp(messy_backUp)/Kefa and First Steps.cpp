#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int arr[n+1],i,x=0,maxx=0,a;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            x=1;
        }
        else if(arr[i]>=arr[i-1])
            x++;
        else
            x=1;

        maxx=max(x,maxx);
    }

    cout<<maxx;
}
