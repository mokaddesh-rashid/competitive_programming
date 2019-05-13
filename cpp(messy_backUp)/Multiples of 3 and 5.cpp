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

    int t;

    cin >> t;

    while (t--)
    {
        unsigned long long int n, i, j, a, b, c;

    cin >> n;

    n--;

    a = n/3;
    a = a*(a+1)/2;
    a = a*3;

    b = n/5;
    b = b*(b+1)/2;
    b = b*5;

    c = n/15;
    c = c*(c+1)/2;
    c = c*15;

    cout << a+b-c;
    }








}

