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

    long long int i, j, x = 1, y = 0, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        x *= 2;

        y += x;
    }

    cout << y;

    return 0;

}

