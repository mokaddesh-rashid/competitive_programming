#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a,x=0,count0=0;

    for(i=0;i<n;i++)
    {
        cin>>a;
        arr[i]=a;
        a--;
        x+=a;
    }
}
