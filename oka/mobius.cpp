#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;
long long  arr[10000000+10], mob[10000000+10], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
void sieve( long long n )
{
    long long  m = n, i, j, cnt;
    for( i=2; i<=m; i ++ )
    {        cnt = 1;
        if( arr[i] == 0 )
         {
             long long  l = i*i;
             arr[i]++;
             for( j = i+i; j <= n; j += i )
                {    if( j % l == 0 )
                         mob[j] = 0;
                    cnt++;
                    arr[j]++;
                }
        }
    }

    for( i=2; i<=n; i++ )
    {
        if( mob[i] != 0 )
        {
            if( arr[i] % 2 )
            {
                mob[i] = -1;
            }
            else
                 mob[i] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    memset( mob, -1, sizeof(mob));
    sieve(10000001); /// range of sieve
    int t;
    cin >> t;
    while( t-- )
    {
        long long i , j, n, m, x;

    cin >> n;

    m = sqrt( n );
    x = n;
    for( i=2; i<=m; i++)
    {
        if( mob[i] == -1 )
        {
            x -= ( n / (i*i) );
        }
        else if( mob[i] == 1 )
        {
            x += ( n / (i*i) );
        }
    }
    cout << x << endl;
    }
}

