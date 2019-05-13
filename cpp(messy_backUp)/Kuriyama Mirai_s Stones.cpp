#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int arr[n+1],ans1[n+1+1],x=0,ans2[n+1+1],i,j,a,b,c,m;

    ans1[0]=0;
    ans2[0]=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        x+=arr[i];
        ans1[i+1]=x;
    }

    sort(arr,arr+n);

    x=0;
    for(i=0;i<n;i++)
    {
        x+=arr[i];
        ans2[i+1]=x;
    }

    cin>>m;

    for(i=0;i<m;i++)
    {
       cin>>a>>b>>c;

       if(a==1)
       {
          cout<<ans1[c]-ans1[b-1];
       }
       else
        cout<<ans2[c]-ans2[b-1];

       cout<<endl;
    }



}
