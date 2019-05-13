
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

    long long int i, j, x, y, n, m, a, b, c;

    cin >> a >> b >> c;

    x = max( a, b);
    x = max( x, c);

    cout << min( (a+b+c)/3, a+b+c-x );

    return 0;

}

