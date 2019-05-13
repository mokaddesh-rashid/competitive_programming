#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int value[n+1],sorted[n+1],i,x,a,b,c=0,maxx,minn,manage=0;

    for(i=0;i<n;i++)
    {
        cin>>value[i];

        if(i==0)
        {
            minn=value[i];
            maxx=value[i];
        }
        else
        {
            maxx=max(maxx,value[i]);
            minn=min(minn,value[i]);
        }
    }

   // cout<<minn<<endl;

    if(minn<0)
       {
            manage=-1*minn;
            maxx=maxx+maxx;
            minn=0;
       }

     //cout<<manage<<endl;

    int pos[maxx+1+manage];

    fill_n(pos,maxx+1+manage,0);

     for(i=0;i<n;i++)
     {
         pos[value[i]+manage]++;
     }

     for(i=minn;i<=maxx;i++)
     {
         c=c+pos[i];
         pos[i]=c;
     }
     for(i=0;i<n;i++)
     {
         pos[value[i]+manage]--;
        sorted[pos[value[i]+manage]]=value[i];
     }
     for(i=0;i<n;i++)
         cout<<sorted[i]<<' ';



}
