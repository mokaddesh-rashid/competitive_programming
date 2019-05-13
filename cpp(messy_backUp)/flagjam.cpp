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

    long long int n;

    cin >> n;

    long long int i, j, a, b, x=1;

    for( i=0; i<n; i++)
    {
        if( i==0 )
            x *= 2;
        else if( i+1 < n)
        {
            x *= 2;
        }
    }

    cout << x;




}

