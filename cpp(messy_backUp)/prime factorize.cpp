#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;

int arr[10000001], prime[10000001], k ;


using namespace std;

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



int main()
{
    ios::sync_with_stdio(false);

    int i, j,  y, n, m, c, fac[1111], a = 0;

    cin >> c ;

    n = sqrt(c);
    sieve( n );

    for( i=0; i<k; i++)
    {
        while( c % prime[i] == 0 )
        {
            fac[a] = prime[i];
            a++;
            c /= prime[i];
        }
    }

    if( c != 1 )
    {
           fac[a] = c;
            a++;
    }

    for( i=0; i<a; i++)
        cout << fac[i] << ' ';


    return 0;

}

