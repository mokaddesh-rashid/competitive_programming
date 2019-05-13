#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,j,a,b,c,x=0,pos[1111]={0},t=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    while(x<n)
    {
      for(i=0;i<n;i++)
    {
        if(arr[i]<=x&&pos[i]==0)
        {
            x++;
            pos[i]=1;
        }
    }
    t++;
    if(x>=n)
        break;

      for(i=n-1;i>=0;i--)
    {
        if(arr[i]<=x&&pos[i]==0)
        {
            x++;
            pos[i]=1;
        }
    }
    t++;


    }

    cout<<t-1;
}
