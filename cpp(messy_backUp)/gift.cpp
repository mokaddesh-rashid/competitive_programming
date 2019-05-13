#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int ar[111]={0},i,x,t;

    for(i=0;i<n;i++)
    {
        cin>>x;

        ar[x]=i+1;
        //cout<<ar[x]<<endl;
    }

     for(i=1;i<=n;i++)
        cout<<ar[i]<<' ';
}

