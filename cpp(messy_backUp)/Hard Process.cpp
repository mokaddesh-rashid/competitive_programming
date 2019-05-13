#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


//set<int>::iterator ii;

int arr[1000000], ast[1000000], brr[1000000], in[1000000], crr[1000000], cst[1000000];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( arr, 0, sizeof( arr ) );
    memset( brr, 0, sizeof( brr ) );
    int i, j, x = 0, y = 0, n, m, a, k, on = 0, of = 0;

    cin >> n >> k;


    for( i=0; i<n; i++ )
    {
        cin >> in[i];

        if( in[i] == 1 )
            on = 1;
        else
            of = 1;
    }

    for( i=0; i<n; i++)
    {
        if( in[i] == 1 )
        {
            if( brr[y] != 0 )
                y++;
            if( arr[x] == 0 )
            {
                ast[x] = i;
            }
            arr[x]++;

            if( i == n-1 )
                x++;
        }
        else
        {
            if( arr[x] != 0 )
                x++;
            if( brr[y] == 0 )
            {
                cst[y] = i;
            }

            brr[y]++;
            if( i == n-1 )
                y++;
        }
    }

    int yoo = 0, bro = 0, high = 0;

       for( i=0; i<x; i++)
       {
           if( yoo < arr[i] )
           {
               yoo = arr[i];
               bro = ast[i];
           }
       }


    a = 0;
    for( i=0; i<y; i++ )
    {
        a += brr[i];

        crr[i] = a;
    }

    a = 0;
    int up, maxx = 0, st, en;
    for( i=0; i<x; i++ )
    {
        if( cst[a] < ast[i] )
            a++;

        if( a != 0 )
        {
            up = upper_bound( crr, crr+y, k+crr[a-1] ) - crr;

        }
        else
        {
            up = upper_bound( crr, crr+y, k ) - crr;

        }
        //cout << up << endl;
        if( up == y )
           {
               if( maxx < n-ast[i] )
               {
                   st = ast[i];
                   en = n;
               }
                maxx = max( n - ast[i], maxx );
           }
        else
            {
               if( maxx < n-ast[i] )
               {
                   st = ast[i];
                   en = cst[up]-1;
               }
                maxx = max( cst[up] - ast[i], maxx );
           }


    }

    if( maxx < yoo+k )
    {
       if( on == 0 )
       {
           cout << min( k, n ) << endl;

           for( i=0; i<n; i++, k-- )
           {
               if( k > 0 )
                cout << 1 << ' ';
               else
                cout << 0 << ' ';
           }
       }
       else if( of == 0 )
       {
           cout << n << endl;

           for( i=0; i<n; i++, k-- )
           {
                cout << 1 << ' ';
           }
       }

       else
       {
           int a = 0;

           for( i=0; i<n; i++)
           {
               if( i == bro )
                a = 1;

               if( in[i] == 0 && a == 1 && k > 0 )
               {
                   in[i] = 1;
                   k--;
               }


               cout << in[i] << ' ';
           }
       }



    }

     else
     {
        // cout << maxx << endl;
          int a = 0;

           for( i=0; i<n; i++)
           {
               if( i == st )
                a = 1;

               if( in[i] == 0 && a == 1 && k > 0 )
               {
                   in[i] = 1;
                   k--;
               }

               cout << in[i] << ' ';
           }
    }








    return 0;

}


