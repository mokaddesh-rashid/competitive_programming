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

    long long int t;

    cin >> t;

    while( t-- )
    {
        long long int i, j, x, y, n, m, st = 0, en = 0, mid, k, l ;

    cin >> n >> k ;

    long long int arr[n+1];

    for( i=0; i<n; i++)
    {
        cin >> arr[i];

        en += arr[i];

    }

    l = en;


    while( st <= en )
    {
        mid = (st+en) / 2;



        long long int maxx = 0, t = 0;

        y = 0;
        x = 1;

        for( i=0; i<n; i++ )
        {

            if( arr[i] > mid )
                  x = k + 1;

           if( max( y, arr[i] ) * ( t+1 ) <= mid )
            {
                  y = max( y, arr[i] );
                  t++;
            }

           else
           {
               x++;
               y = arr[i];
               t = 1;

           }
        }

        if( x <= k )
        {
            en = mid-1;
            l = min( l, mid );
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << l << endl;
    }

    return 0;

}

