#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    int a,i,j,x=0,y,z;


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a;

            if(a==1&&(i==0||j==0||i==n-1||j==m-1))
                x=1;
        }
    }

    if(x==1)
        cout<<2;
    else
        cout<<4;
}
