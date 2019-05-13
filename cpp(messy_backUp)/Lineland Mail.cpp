#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int arr[n+1],dis[n+1],total[n+1],a,x=0,b;

    dis[0]=0;
    total[0]=0;

    for(int i=0 ;i<n ;i++)
    {
        cin>>arr[i];

        if(i!=0)
        {
            dis[i]=arr[i]-arr[i-1];
            x+=dis[i];
            total[i]=x;
        }
    }

     for(int i=0 ;i<n ;i++)
     {
         if(i==0)
         {
             cout<<dis[1]<<' '<<total[n-1]<<endl;
         }
         else if(i==n-1)
         {
             cout<<dis[n-1]<<' '<<total[n-1]<<endl;
         }
         else
         {
             cout<<min(dis[i],dis[i+1])<<' '<<max(total[i],total[n-1]-total[i])<<endl;
         }
     }



    /*for(int i=1 ;i<n ;i++)
        cout<< dis[i]<<' ';

    cout<<endl;

     for(int i=1 ;i<n ;i++)
        cout<< total[i]<<' ';*/
}
