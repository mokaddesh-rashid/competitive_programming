#include<iostream>
#include <algorithm>
#include<iomanip>

using namespace std;

int main()
{
    cout << std::fixed;
    cout << std::setprecision(5);

    std::ios::sync_with_stdio(false);
     long long int n,w;

    cin>>n>>w;

    long long int arr[2*n+1],ans,i,a,b,c;

     for(i=0;i<2*n;i++)
        cin>>arr[i];

     sort(arr, arr + (2*n+1));

     long double maxx=arr[n],minn=arr[0];

     //cout<<maxx<<endl<<minn<<endl;

     if(maxx/2<=minn)
     {
          //cout<<0<<endl;
        long double ans,check;

        ans=(n*maxx)+(n*maxx/2);

        check=w;


        if(ans>check)
          cout<<check;

        else
            cout<<ans;
     }

     else if(maxx/2>minn)
     {
        // cout<<1<<endl;
        long double ans,check;

        ans=(n*minn)+(n*(minn*2));

        check=w;


        if(ans>check)
          cout<<check;

        else
            cout<<ans;

     }


     else  if(minn*2<maxx)
     {
         // cout<<2<<endl;
         double ans,check;

        ans=(n*minn)+n*(minn*2);

        check=w;


        if(ans>check)
          cout<<check;

        else
            cout<<ans;
     }




}
