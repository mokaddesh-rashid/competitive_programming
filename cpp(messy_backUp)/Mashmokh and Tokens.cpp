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

    long long int n, a, b, i, j, x, t, y, w, s;

    cin >> n >> a >> b;


    for( i=0; i<n; i++)
    {
        cin >> w;

        t = (long long ) w*a;
        s = (long long) t % b;

        cout << s / a <<' ';

    }



}

