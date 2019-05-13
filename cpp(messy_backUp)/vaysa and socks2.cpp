#include<iostream>

using namespace std;

int main()
{
    int n,m,i=0,x=0,a,b=0;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        x++;
        if(x==m)
        {
            n++;
            x=0;
        }
    }

    cout<<n;

}
