#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n,i,x=0,y=0;

    cin>>n;

    if(n%2==0)
    {
    cout<<n/2;
    }

    if(n%2==1)
    {

    cout<<-(n+1)/2;

    }
}
