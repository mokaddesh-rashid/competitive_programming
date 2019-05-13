#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],time[n+1],i,x=0,a,b,c;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(i==0)
        {
            time[i]=arr[i]+1;
        }
        else if(arr[i]<arr[i-1])
        {
            x++;
            time[i]=arr[i-1]-arr[i]+1;

        }
        else if(arr[i]>=arr[i-1])
        {
            x++;
            time[i]=arr[i]-arr[i-1]+1;

        }
    }
     for(i=0;i<n;i++)
       {
           x+=time[i];
           //cout<<time[i]<<' ';
       }

     cout<<x;
}
