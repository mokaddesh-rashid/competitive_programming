#include<iostream>

using namespace std;

int main()
{
    int time[24][62]={0},i,n,a,b,c,d,h,m,x=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>h>>m;

        time[h][m]++;
        x=max(x,time[h][m]);
    }

    cout<<x;




}
