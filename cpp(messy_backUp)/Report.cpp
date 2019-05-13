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

    int i, j, x = 0, y, n, m, a = 0, b = -1;


    scanf( "%d %d", &n, &m);

    int arr[n+1], yo[m+1], bro[m+1], high[n+1], zone[m+1], brr[n+1];

    memset( zone, 0, sizeof(zone) );
    memset( high, 0, sizeof(high) );

    for( i=0; i<n; i++)
         {
             scanf( "%d", &arr[i]);
             brr[i] = arr[i];
         }


    for( i=0; i<m; i++)
    {
        scanf( "%d %d", &yo[i], &bro[i]);
    }

    for( i=m-1; i>=0; i--)
    {
        if( i == m-1 )
        {
            a = bro[i];
            zone[i]++;
        }
        else if( a < bro[i] )
        {
            a = bro[i];
            zone[i]++;
        }
    }

    a = 0;
    b = 0;

    for( i=0; i<m; i++ )
    {
        if( zone[i] == 1 )
        {
            if( x == 0 )
               {
                   x = bro[i]-1;
               }

              if( yo[i] != b )
            {
               high[bro[i]-1] = yo[i];
               b = yo[i];
            }
        }
    }


    sort( brr, brr+x+1);

    a = 0;
    b = x;
    y = x;
    int    z = 0;
    while( y >= 0  )
    {
        if( high[y] != 0 )
            z = high[y];

        if( z == 2 )
        {
            arr[y] = brr[a];
            y--;
            a++;
        }
        else //if( z == 2 )
        {
            arr[y] = brr[x];
            y--;
            x--;
        }

    }

    for( i=0; i<n; i++)
        printf("%d ",arr[i]);// << ' ';







    return 0;

}
