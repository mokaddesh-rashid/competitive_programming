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



    while(true)
    {
        long long int n, m, i, j, a, b, c,arr[11]={0},brr[11]={0}, x=0;

   cin >> n >> m;

   if(n==0 && m==0)
    break;

   for( i=0; i<n; i++)
   {
       cin >> a;

       while(a>1)
       {
          if( a == 2 )
          {
              arr[2]++;
          }

       else if( a == 3 )
       {
            arr[3]++;
       }
       else if( a == 4 )
       {
            arr[2] += 2;
       }
       else if( a == 5 )
       {
            arr[5]++;
       }
       else if( a == 6 )
       {
            arr[3]++;
            arr[2]++;
       }
       else if( a == 7 )
       {
            arr[7]++;
       }
       else if( a == 8 )
       {
            arr[2] += 3;
       }
       else if( a == 9 )
       {
            arr[3] += 2;
       }



       a--;

       }
   }

   for( i=0; i<m; i++)
   {
       cin >> b;

       while(b>1)
       {
          if( b == 2 )
          {
              brr[2]++;
          }

       else if( b == 3 )
       {
            brr[3]++;
       }
       else if( b == 4 )
       {
            brr[2] += 2;
       }
       else if( b == 5 )
       {
            brr[5]++;
       }
       else if( b == 6 )
       {
            brr[3]++;
            brr[2]++;
       }
       else if( b == 7 )
       {
            brr[7]++;
       }
       else if( b == 8 )
       {
            brr[2] += 3;
       }
       else if( b == 9 )
       {
            brr[3] += 2;
       }



       b--;

       }
   }

   for(i=0 ;i<=9 ;i++)
   {
       if(arr[i]!=brr[i])
          x=1;
   }

   if( x==0 )
    cout << "YES\n";
   else
    cout << "NO\n";



    }







}

