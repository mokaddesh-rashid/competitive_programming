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

    int t;

    cin >> t;

    while ( t-- )
    {
        long long int i, j, x=0, y=0, n, m, a, b, z=0;

    cin >> n;

    long long int arr[n+1], hrr[n+1];


    for( i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort ( arr, arr+n);

    for( i=0; i<n; i++)
    {

            if( x == 0 && n == 1 )
           {

               hrr[0] = 1;
               z++;
           }
           else if( x == 0 )
           {
               x++;
           }

           else if( arr[i] == arr[i-1] )
           {
            x++;
                if( i == n-1 )
                   {
                     hrr[z] = x;
                     z++;
                     x = 1;
                   }

           }

           else
          {
              if( z == 0 )
                 {
                      hrr[z] = x;
                      z++;
                      x = 1;
                 }
              else
              {
                   hrr[z] = x;
                   z++;
                   x = 1;

               if( i == n-1 )
                   {
                     hrr[z] = x;
                     z++;
                     x = 1;
                   }
              }

          }

    }

    int ans = 0;

    sort( hrr, hrr+z, greater<int>());

    for( i=0; i<z; i++)
    {
        b = 0;
        while( hrr[i] != 0  && b == 0)
        {
            b = 1;
            for( j=0; j<z; j++)
            {
               if( i != j && hrr[i] > 0 && hrr[j] > 0)
               {
                   ans++;
                   hrr[i]--;
                   hrr[j]--;
               }

               if( i != j && hrr[j] > 0)
                   b = 0;
               if( hrr[i] == 0 )
                break;
            }
        }
    }

    for( i=0; i<z; i++)
    {
        if( hrr[i] != 0 )
        {
            ans += hrr[i];
        }
    }



    cout << ans <<endl;

    }

    return 0;

}

