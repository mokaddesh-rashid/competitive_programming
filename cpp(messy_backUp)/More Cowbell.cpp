#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

     int n,k;

     cin >> n >> k;

    long long int arr[n+1],i,j,a,b,c,d=0,maxx=0,x;


     for(i=0;i<n;i++)
     {
         cin >> arr[i];
         d = max(d,arr[i]);
     }


     if(n<=k)
        cout<<d;

    else
     {
         j = n-k-1;

     for(i=n-k;i<n;i++)
     {
         //cout << n-k <<' '<<n<<endl;
         if( j >= 0)
         {
            // cout<< arr[i]<<' '<<arr[j]<<endl;
             x = arr[i]+arr[j];
             j--;
         }

         else
            x = arr[i];

         maxx= max(x,maxx);
     }

         cout << maxx;

     }



}

