#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,m;


    cin>>n>>m;

    long long int arr[m+1][n+1],cand[n+1],i,maii,poss,x;

    fill_n(cand,n,0);

    for(i=0;i<m;i++)
    {
        long long int vote[n+1],maxx,pos;

        for(x=0;x<n;x++)
        {
            cin >> vote[x];
        }

        for(x=0;x<n;x++)
        {
           if(x==0)
           {
               maxx=vote[x];
               pos=x;

           }

           else if(maxx<vote[x])
           {
               maxx=vote[x];
               pos=x;
           }
        }

        cand[pos]++;
    }

    for(i=0;i<n;i++)
        {
           if(i==0)
           {
               maii=cand[i];
               poss=i;

           }

           else if(maii<cand[i])
           {
               maii=cand[i];
               poss=i;
           }
        }

    cout<<poss+1;
}
