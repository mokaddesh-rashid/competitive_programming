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

    long long int i, j, x, y, n, m;

    cin >> n;

    n = n*(n+1);

    n /= 2;

    n *= 6;

    n++;

    cout << n;

    return 0;

}

