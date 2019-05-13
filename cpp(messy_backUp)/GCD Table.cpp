#include<iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int arr[n*n+1],i,j,a,b,x=0,ans[n+1];


    for(i=0;i<n*n;i++)
    {
        cin>>arr[i];

       a=0;
      for(j=0;j<x+1;j++)
      {
          if(ans[j]==arr[i])
            a=1;
      }
      if(a==0)
      {
          ans[x]=arr[i];
          x++;
      }
    }


    //sort(ot,ot+n);
    sort(ans, ans+x, greater<int>());

    for(i=0;i<n;i++)
    {
        if(i>=x)
            cout<<arr[x-1];
        else
            cout<<ans[i]<<' ';
    }





}
