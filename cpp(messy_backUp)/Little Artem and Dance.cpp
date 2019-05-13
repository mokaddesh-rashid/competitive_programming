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
#define LL           long long


//set<int>::iterator ii;

int arr[1000010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y = 0, n, m, a = 1, b, c, z;

    cin >> n >> m ;

    for( i=0; i<m; i++ )
    {
        cin >> b ;

        if( b == 1 )
        {
            cin >> c;
            x += c;
            y += c;
        }
        else
        {
           if( a == 1 )
           {
               x++;
               y--;
               a = 2;
           }
           else
           {
               x--;
               y++;
               a = 1;
           }
        }
    }

    for( i=1; i<=n; i++ )
    {
        if( i % 2 )
        {
            a = i + x;
            a %= n;
            cout << i << ' ' << a << endl;
            if( a >= 0 )
            {
                if( a != 0 )
                    arr[a] = i;
                else
                    arr[n] = i;
            }
            else
            {
                j = i;
                while( a < 0 )
                {
                    j--;
                    if( j == 0 )
                        j = n;
                    a++;
                }

                    arr[j] = i;

            }
        }
        else
        {
            a = i + y;
            a %= n;
            cout << i << ' ' << a << endl;
            if( a >= 0 )
            {
                if( a != 0 )
                    arr[a] = i;
                else
                    arr[n] = i;
            }
            else
            {
                j = i;
                while( a < 0 )
                {
                    j--;
                    if( j == 0 )
                        j = n;
                    a++;
                }

                    arr[j] = i;

            }
        }
    }

    for( i=1; i<=n; i++ )
    {
        cout << arr[i] << ' ';
    }



    return 0;

}


