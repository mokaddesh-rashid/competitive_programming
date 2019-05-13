#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int n,x,a,b,c,i,j;

    cin>>n;

    int arr[100]={0},re[111]={0},brr[111]={0},ans[111]={0};

    x=0;

    for(i=1;i<n;i++)
    {
       cin>>a;
       x+=a;
       arr[i]=x;
    }




     for(i=0;i<n-1;i++)
    {
       cin>>re[i];
    }

    x=0;

    for(i=n-2;i>=0;i--)
    {
        a=re[i];
        x+=a;
        brr[i]=x;

    }



     for(i=0;i<n;i++)
    {

      cin>>a;
      ans[i]=arr[i]+a+brr[i];
    }

    sort(ans,ans+n);

    cout<<ans[0]+ans[1];



}
