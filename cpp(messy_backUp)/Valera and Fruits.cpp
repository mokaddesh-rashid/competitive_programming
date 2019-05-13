#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    int arr[3333]={0},i,j,a,b,c,x=0;


    for(i=0;i<n;i++)
    {
        cin>>a>>b;

        arr[a]+=b;
    }


    for(i=3001;i>0;i--)
    {
       if(arr[i]<m)
       {

           a=m-arr[i];
           //cout<<i<<' '<<a<<endl;
           if(a<=arr[i-1])
           {
               arr[i]+=a;
               arr[i-1]-=a;
           }
           else
           {
               arr[i]+=arr[i-1];
               arr[i-1]=0;
           }
      }
    }
    /* for(i=0;i<=n+1;i++)
    {
       cout<<arr[i]<<' ';
    }
    cout<<endl;*/

     for(i=0;i<=3001;i++)
    {
        if(arr[i]>=m)
           x+=m;
        else
            x+=arr[i];

    }

    cout<<x;
}
