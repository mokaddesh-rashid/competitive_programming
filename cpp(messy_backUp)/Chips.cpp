#include<iostream>

using namespace std;

int main()
{
    int n,m,i;

    cin>>n>>m;

    i=1;

    while(m>=i)
    {
        m=m-i;

        i=(i+1)%(n+1);
    }

    cout<<m;
}
