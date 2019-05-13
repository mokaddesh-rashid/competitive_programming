#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,m;

    cin>>n>>m;

    long long int arr[n+1],have[10*10*10*3+2]={0},prob[m+1],i,j,x=0,a;


    for(i=0;i<n;i++)
        cin>>arr[i];

    for(i=0;i<m;i++)
    {
       cin>>prob[i];
    }

    sort(prob,prob+m);

    for(i=0;i<n;i++)
    {
        a=0;
        for(j=0;j<m;j++)
        {
            if(have[j]==0&&prob[j]>=arr[i])
            {
                have[j]=1;
                a=1;
                break;
            }
        }

        if(a==1)
            x++;
    }

    cout<<n-x;

}
