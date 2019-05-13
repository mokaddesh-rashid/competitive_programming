#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 1, y = 2, n, m, a, b;

    cin >> n >> a >> b ;

    int arr[a+1][b+1];

    for( i=0; i<a; i++)
    {
        if( i % 2 == 0 )
        {
            for( j=0; j<b; j++ )
            {
                if( x <= n && j % 2 == 0 )
                {
                   arr[i][j] = x;
                   x += 2;
                }
                else if ( y <= n )
                {
                    arr[i][j] = y;
                    y+=2;
                }
                else
                    arr[i][j] = 0;
            }

        }
        else
        {
            for( j=0; j<b; j++ )
            {
                if( x <= n && j % 2 == 1 )
                {
                   arr[i][j] = x;
                   x += 2;
                }
                else if ( y <= n )
                {
                    arr[i][j] = y;
                    y+=2;
                }
                else
                    arr[i][j] = 0;
            }

        }
    }

    if( x <= n || y <= n )
    {
        cout << -1;
    }
    else
    {

    for( i=0; i<a; i++)
    {
        for( j=0; j<b; j++)
            cout << arr[i][j] << ' ';

        cout << endl;
    }
    }



    return 0;

}

