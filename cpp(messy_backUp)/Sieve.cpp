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

int arr[10000010], prime[10000010];

int main()
{
    ios::sync_with_stdio(false);

    int i, j, k =0, y, n, m;

    n = 10000009;

    m = sqrt(n);



    memset( arr, 0, sizeof(arr));

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
    prime[0] = 2;
    k ++;

    for( i=3 ; i <= n ; i +=2 )
    {
        if( arr[i] == 0 )
        {
            prime[k] = i;
            k++;
           // cout << i << ' ';
        }
    }

    cout <<k;


    return 0;

}

