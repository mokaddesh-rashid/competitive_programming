#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n,x,i,a=0;

    cin>>n>>x;

    for(i=1;i<=n;i++)
    {
        if(x%i==0&&x/i<=n)
            a++;
    }


    cout<<a;



}
