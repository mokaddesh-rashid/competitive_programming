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


    long long  int n;

    cin >> n;

    long long int arr[200000+5] = {0}, i, j, a, b, c=0;

    for( i=0; i<n; i++)
    {
        cin >> a;

        arr[a] = i+1;
    }

    for( i=2; i<=n ;i++)
    {
        b = max(arr[i-1]-arr[i],arr[i]-arr[i-1]);

        c += b;
    }

    cout << c;



}

