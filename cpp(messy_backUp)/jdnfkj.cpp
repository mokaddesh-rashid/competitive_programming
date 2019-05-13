#include<iostream>

using namespace std;


int main()
{
    int n;

    cin>>n;

    int vote[n+1],need=0,i,x,a,b,maxx,pos;

    for(i=0;i<n;i++)
    {
        cin>>vote[i];

    }

    while(true)
    {
        for(i=0;i<n;i++)//kon canidate r vote highest ta bar krbe ai loop
        {
            if(i==0)
            {
                maxx=vote[i];
                x=i;
            }

            else if(maxx<=vote[i])
            {
                maxx=vote[i];
                x=i;
            }
        }

        if(x==0)//means tr vote highest
        {
           break;
        }

        else// tr worst opponentr vote kintasos
        {
            need++;
            vote[x]--;
            vote[0]++;
        }

    }


    cout<<need;
}

