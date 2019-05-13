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

    long long int n, a;

    cin >> n;

    if( n%2 || n <= 4 )
        cout << 0;

    else
    {
        n /= 2;

        a = n;

        a /= 2;

        if( n%2 == 0 )
            a--;

        cout << a;
    }





}

