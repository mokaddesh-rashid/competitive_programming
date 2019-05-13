
#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b;

    int ar[11];

    cin>>a;

    for(n=a;n>0;n/=i)
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
            break;
        }
    }
}
