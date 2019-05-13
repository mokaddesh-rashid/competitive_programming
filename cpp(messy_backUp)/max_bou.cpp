#include<iostream>

using namespace std;

int main()
{
    int n,ar[10001],i,maxx;

    cin>>n;
    for(i=0;i<n;i++) cin>>ar[i];
    for(i=0;i<n;i++)
    {
        if(i==0) maxx=ar[i];
        else if(maxx<ar[i]) maxx=ar[i];
    }
    cout<<maxx<<endl;
}
