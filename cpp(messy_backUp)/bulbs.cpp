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

    int n, m, i, j, x, a=0, arr[1000] ={0}, b, c;


    cin >> n >> m;

    for( i=0; i<n; i++)
    {
        cin >> x;

        for( j=0; j<x; j++)
        {
            cin >> b;
            arr[b]++;
        }
    }
    for( i=1; i<= m; i++)
    {
        if( arr[i] == 0 )
             a = 1;
    }

    if( a==0 )
        cout << "YES";
    else
        cout << "NO";











}
