#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long arr[n+1],x=0,a=1,b,i;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(i=0;i<n;i++)
    {
       b=a-arr[i];

       if(b<0)
        b*=-1;

       x+=b;
       a++;
    }

    cout<<x;


}
