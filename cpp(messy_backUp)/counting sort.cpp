#include<iostream>

using namespace std;


int main()
{
    int n,maxx;

    cin>>n;

    int value[n+1],i,sorted[n+1];

    for(i=0;i<n;i++)
        {
            cin>>value[i];
            if(i==0)
                maxx=value[i];
            else
                maxx=max(maxx,value[i]);

        }

    int times[maxx+1];
    fill_n(times, maxx+1, 0);

    int pos[maxx+1],c=0;


    for(i=0;i<n;i++)
    {
        times[value[i]]++;
    }



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
