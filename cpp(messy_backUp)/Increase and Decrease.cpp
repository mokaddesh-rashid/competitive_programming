#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    long long int i,j,a,b,c,d,x=0;

    for(i=0;i<n;i++)
    {
        cin>>a;

        x+=a;
    }

    if(x%n)
        cout<<n-1;
    else
        cout<<n;
}
