#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int t;

    cin>>t;

    while(t>0)
    {
      int n,m;

    cin>>n>>m;

    int arr[n+1],i,j,a=0,b,x=0,y=0;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        y+=arr[i];
    }

    sort(arr,arr+n);

    i=0;
    while(x<m&&i<n)
    {

        x+=arr[i];
        a++;
        i++;

    }



    if(x-arr[0]>=m)
        {
            a--;
        }



    cout<<a;

    t--;
    if(t>0)
        cout<<endl;
    }
}
