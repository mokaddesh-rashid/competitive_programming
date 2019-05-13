#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;

int arr[100001], prime[100001], k ;

void sieve( int n )
{
   int  m = sqrt(n);
   memset(arr, 0, sizeof(prime));
   k = 0;
   for(int i=3 ; i <= m ; i += 2 )
    {
        if(arr[i] == 0 )
        {
            for(int j=i*i; j <= n; j += (2*i) )
            {
               arr[j]++;
            }
        }
    }
    prime[0] = 2;
    k++;

    for(int i=3 ; i <= n ; i +=2 )
    {
        if(arr[i] == 0 )
        {
            prime[k] = i;
            k++;
           // cout << i << ' ';
        }
    }
}


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int i, j, n, m, c, fac[1111], a = 0, x = 0, y = 1 , z, d;

    cin >> c ;

    n = sqrt(c);
    sieve( n );

    for( i=0; i<k; i++)
    {
        if( c % prime[i] == 0 )
        {
             x = prime[i];
            while( c % prime[i] == 0 )
        {
            x  *= prime[i];
            c /= prime[i];
        }

        x--;

        x /= (prime[i]-1);

        y = y * x;
        }
    }

    if( c != 1 )
    {
        d = c * c;
        d--;
        d /= (c-1);
        y *= d;
    }

    cout << y;


    return 0;

}


