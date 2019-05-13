#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],ot[300+2]={0},i,j,a,b,c,maxx,t=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(i==0)
        {
            maxx=arr[i];
            t=0;
        }

        else if(maxx<arr[i])
        {
            maxx=arr[i];
            t=0;
        }
        else if(maxx==arr[i])
        {
           t++;
        }

    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]<=arr[j])
                ot[i]++;
        }
    }
}


