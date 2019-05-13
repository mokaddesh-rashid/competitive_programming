
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

    long long  i, j, x, y, n, m, maxx = 0, z;

    cin >> n;

    long long arr[n+1], brr[n+1];

    for( i=0; i<n; i++)
        cin >> arr[i];

    for( i=0; i<n; i++)
        cin >> brr[i];

    for( i=0; i<n; i++)
    {
        x = 0;

        for( j=i; j<n; j++)
        {
            if( j == i )
            {
                y = arr[j];
                z = brr[j];
            }
            else
               {
                    y = y | arr[j];
                    z = z | brr[j];
               }


        x = y + z;
        maxx = max( x, maxx);
        }




    }

    cout << maxx;



    return 0;

}
