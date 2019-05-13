#include<iostream>

using namespace std;

int main()
{
    int n,ar[10001],i,minn;

    cin>>n;
    for(i=0;i<n;i++) cin>>ar[i];
    for(i=0;i<n;i++)
    {
        if(i==0) minn=ar[i];
        else if(minn>ar[i]) minn=ar[i];
    }
    cout<<minn<<endl;
}

