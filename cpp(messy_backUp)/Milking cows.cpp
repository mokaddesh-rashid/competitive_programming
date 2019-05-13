#include<iostream>


using namespace std;

int main()
{
    long long int o=0,a=0,n;

    cin>>n;

    long long int arr[n+1],i,j,x=0,y=0;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(arr[i]==0)
            o++;
        else
            a++;
    }

    if(a>=o)
    {
       for(i=0;i<n;i++)
    {
        if(arr[i]==1)
            x++;
        else if(arr[i]==0)
        {
            y+=x;
        }
    }

    }

    else
    {
           for(i=n-1;i>=0;i--)
    {
        if(arr[i]==0)
            x++;
        else if(arr[i]==1)
        {
            y+=x;
        }
    }

    }

    cout<<y;


}
