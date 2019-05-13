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

    long long int i, j, x, y, n, m, k, a, b, c, z = 0, l;

    cin >> n >> k;

    l = n - k;
    k--;

    long long int arr[n+1][n+1];

    x = 1;
    y = n*n;


    for( i=0; i<n; i++)
    {
        for( j = 0; j<n ; j++)

            {
                if ( j < k )
                {
                    arr[i][j] = x;
                    x++;
                }

                else if ( j == k )
                {
                   a = y - l;
                   z += a;
                   arr[i][j] = a;
                   y = a-1;
                   a++;
                }

                else
                {
                    arr[i][j] = a;
                    a++;
                }
            }
    }

    cout << z << endl;

    for( i=0; i<n; i++)
    {
        for( j = 0; j<n ; j++)

            {
               cout << arr[i][j] << ' ';
            }

        cout << endl;
    }

    return 0;

}

