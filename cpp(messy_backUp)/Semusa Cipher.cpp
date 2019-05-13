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

    while( t-- )
    {
        int n;

    cin >> n;

    int arr[n+1], i, j, a, b, x=0, y=n-1;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    for( i=0; i<n; i++)
    {
        if( i%2 )
        {
            cout << arr[x] << ' ';
            x++;
        }
        else
        {
            cout << arr[y] << ' ';
            y--;
        }
    }

    cout << endl;
    }



}

