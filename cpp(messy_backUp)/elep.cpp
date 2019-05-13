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

    long long int x, a, b =0;

    cin >> x;

    a = x / 5;

    if( x%5 )
        b++;

    cout << a+b;



    return 0;

}

