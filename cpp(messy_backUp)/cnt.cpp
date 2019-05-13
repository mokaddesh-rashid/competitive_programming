#include<iostream>

using namespace std;


int main()
{
    int n,maxx;
    int value[1001],i,sorted[1001],pos[1001],c,times[1001];

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>value[i];
        if(i==0) maxx=value[i];
        else maxx=max(maxx,value[i]);
    }
    for(i=0;i<=maxx;i++) times[i]=0;

    c=0;
    for(i=0;i<n;i++)
        times[value[i]]++;

    for(i=0;i<=maxx;i++)
    {
        c=c+times[i];
        pos[i]=c;
    }

    for(i=0;i<n;i++)
    {
        int x=value[i];
        pos[x]--;
        sorted[pos[x]]=x;

    }

    for(i=0;i<n;i++)
        cout<<sorted[i]<<' ';





}

