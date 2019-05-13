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
   // ios::sync_with_stdio(false);

    long double i, j, x, y, n, m;

    cin >> n >> m;

    x = (long double) .000000011;

    x = (long double) m * x;

     cout.precision(7);

    x = n*x;

    cout << fixed << x;

    return 0;

}

