#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int ncr[800][10];

long long int nCr(int n, int r)
{
    if(r == n || r == 0) return 1;
    if(r == 1) return n;

    if(ncr[n][r] != -1) return ncr[n][r];

    return (ncr[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)));
}

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m;

    cin >> n;

    memset( ncr, -1, sizeof(ncr));

    x = nCr( n, 5);

    x += nCr( n, 6);

    x += nCr( n, 7);

    cout << x;

    return 0;

}

