#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b,c,d,m,x,y=0;

    cin>>n>>m;

    for(i=0;i<=min(n,m);i++)
        for(x=0;x<=min(n,m);x++)
    {
        if(x*x+i==n&&x+i*i==m)
            y++;
    }

    cout<<y;
}
