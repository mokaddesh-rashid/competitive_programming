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



long long  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number
void sieve( long long n )
{
    long long  m = sqrt(n), i, j;
    prime[np] = 2;
    np++;
    for( i=3; i<=m; i += 2)
    {
        if( arr[i] == 0 )
         {
            for( j=i*i; j<=n; j += (i+i) )
                arr[j]++;
         }
    }
    for( i=3; i<=n; i += 2)
    {
        if( arr[i] == 0 )
         {
            prime[np] = i;
            np++;
         }
    }


}



void prime_fac( long long  n )
{
    long long  m = sqrt(n);

    for( long long  i=0; i<np && prime[i] <= m ; i++ )
    {
        if( n % prime[i] == 0 )
        {
            long long  a = 0;

            while( n % prime[i] == 0 )
            {
                a++;
                n /= prime[i];

            }
           cout << prime[i] << ' ' << a << endl;
           pfac[nf] = prime[i];
           tim[nf] = a;
           nf++;
           m = sqrt(n);
        }
    }

    if( n != 1 )
    {
           cout << n << ' ' << 1 << endl;
           pfac[nf] = n;
           tim[nf] = 1;
           nf++;
    }
}

long long calval( int pt[][22], int bt[], int bs, int per )
{
    long long val = 1;
}


int bt[1111] = {0}, pt[2222][22], bal[111];

int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));

    //inf;
    //outf;

    np = 0; /// number of prime initially 0

    sieve(10000001); /// range of sieve

    int i, j, x = 1, y, n, m, k;

    cin >> n >> k ;

    m = n-2;

    for( i=0; i<m; i++ )
    {
        bal[i] = i+1;
        //cout << i+1 << ' ';
        pt[0][i] = i+1;
    }

   // cout << endl;

    while( next_permutation( bal , bal+m) )
    {
        for( i=0; i<m; i++ )
        {
            pt[x][i] = bal[i];
           // cout << bal[i] << ' ';
        }

       // cout << endl;
        x++;
    }

    int t, st[11111], di[1111];

    for( i=0; i<m; i++ )
    {
        bt[i] = 1;
        long long val = 1, sum = 0;

        for( j=0; j<x; j++ )
        {
            for( k=2; k <=10; k++ )
            {
              val = calval( pt, bt, k , j );
            }
        }
    }







    return 0;

}


