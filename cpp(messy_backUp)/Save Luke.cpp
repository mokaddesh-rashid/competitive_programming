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

    long long int i, j, x, y, n, m, d, L, v1, v2;

    double ans;

    cin >> d >> L >> v1 >> v2;

    x = L - d;
    y = v1 + v2;

    ans = (double) x / y;

    printf( "%.7lf",ans);

    return 0;

}

