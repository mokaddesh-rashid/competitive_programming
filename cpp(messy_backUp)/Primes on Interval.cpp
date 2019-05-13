#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;


using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int i, j, k =0, y, n, m,  x, z, a, b, c, d, maxd;

    cin >> a >> b >> k ;

    n = b;
    m = sqrt(n);

    int arr[n+1], prime[n+1];

    memset( arr, 0, sizeof(arr));

    arr[0]++;
    arr[1]++;

    for( i=4; i<=n; i+=2)
    {
        arr[i]++;
    }

    for( i=3 ; i <= m ; i += 2 )
    {
        if( arr[i] == 0 )
        {
            for( j=i*i; j <= n; j += (2*i) )
            {
                arr[j]++;
            }
        }
    }

    int p = 0;
    x = a;
    y = a;
    z = 0;
    maxd = 0;

    while( x <= b )
    {
        if( arr[x] == 0 )
            z++;

        if( z == k )
        {
            maxd = max( maxd, x-y+1);
            p = 1;

            while(  z == k )
            {
                 if( arr[y] == 0 )
                      z--;
                  y++;
            }
        }
        else if( x == b )
        {
           maxd = max( maxd, x-y+2);
        }

        x++;
    }

    if( p == 0 )
       cout << -1;
    else
        cout << maxd;






    return 0;

}

