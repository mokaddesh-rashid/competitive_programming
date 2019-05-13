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

    long long int n, x=0;


    cin >> n;

    long long int arr[n+1], i, j, a, b, c=0;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
        x += arr[i];
    }

    a = x/n;

    b = x%n;


    for( i=0; i<n; i++)
    {
        if( arr[i] <= a )
        {
            c += (a-arr[i]);
        }
        else
            b--;
    }
    b = max((long long)0,b);
    cout << c + b;



}

