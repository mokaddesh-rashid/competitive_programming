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

void change( int arr[], int j )
{
    int i=0;

    while( i < j )
    {
        swap( arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    //ios::sync_with_stdio(false);

    int i, j, x, y, n, m, a = 0, b = -1;

    //cin >> n >> m ;

    scanf( "%d %d", &n, &m);

    int arr[n+1], yo[m+1], bro[m+1], high[m+1], zone[m+1];

    memset( zone, 0, sizeof(zone) );

    for( i=0; i<n; i++)
         scanf( "%d", &arr[i]);
        //cin >> arr[i];

    for( i=0; i<m; i++)
    {
        scanf( "%d %d", &yo[i], &bro[i]);
       // cin >> yo[i] >> bro[i];
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
            if( b == 0 && yo[i] == 1 )
            {
                sort( arr, arr+bro[i]);
                b = 1;
            }
            else if( b == 0 && yo[i] == 2 )
            {
                sort( arr, arr+bro[i], greater<int>());
                b = 2;
            }
            else if( yo[i] != b )
            {
               change( arr, bro[i]-1);
               b = yo[i];
            }
        }
    }

    for( i=0; i<n; i++)
        printf("%d ",arr[i]);// << ' ';







    return 0;

}
