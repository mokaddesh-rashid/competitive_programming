#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],item[10*10*10*10*10+2]={0},cbs[n+1],i,x=0,a,b;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        item[arr[i]]++;
    }



    for(i=1;i<=n;i++)
    {
       if(item[i]==0)
       {
           cbs[x]=i;
           x++;
       }
    }


    x=0;

    for(i=0;i<n;i++)
    {
       if(item[arr[i]]>1||arr[i]>n)
       {
           cout<<cbs[x]<<' ';
           x++;
           item[arr[i]]--;
       }

       else
        cout<<arr[i]<<' ';
    }


}
