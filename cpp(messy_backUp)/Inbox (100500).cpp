#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a,b,c,x=0;;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            while(arr[i]==1&&i<n)
            {
               x++;
               i++;
              // cout<<1;
            }
            x++;
             while(arr[i]==0&&i<n)
            {

               i++;
            }
            i--;
        }
    }

    if(x==0)
        cout<<0;

    else
    cout<<x-1;
}
