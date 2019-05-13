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
   // ios::sync_with_stdio(false);

    int i, j, x = 0, y, n, m;

    int arr[5000005], sum[5000005];

    memset( arr, 0, sizeof(arr));

    for( i=2; i<5000005; i++)
    {
        if( arr[i] == 0 )
        {
            j = i+i;



            while( j <= 5000005 )
            {
                int k = 0, l;
                l = j;
                while( l % i == 0)
                {
                    k++;
                    l /= i;
                }
                //cout << i << ' ' << j << ' ' << k << endl;
                arr[j] += k;

                j += i;
            }
        }
    }

    sum[0] = 0;
    sum[1] = 0;

    for( i=2; i<5000005; i++)
    {
        //cout << i << ' ' << arr[i] <<endl;
        x += max(1,arr[i]);
        sum[i] = x;
    }

    int t;

    scanf( "%d", &t);

    while( t-- )
    {
        scanf( "%d %d", &n, &m );
        //cin >> n >> m;

        printf( "%d\n", sum[n] - sum[m]);

        //cout << sum[n] - sum[m] << endl;
    }






    return 0;

}


