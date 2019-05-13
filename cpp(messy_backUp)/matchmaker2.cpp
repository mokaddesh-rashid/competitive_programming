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

    int n, m;

    cin >> n >> m;

    int haa[111][111] = {0}, i, j, a, b, arr[1111] = {0}, exta[m+1], x=0, y=0, z=0;

    for ( i=0 ; i<n; i++)
    {
        cin >> a >> b;

        haa[b][a]++;
        arr[b]++;
    }

    for ( i=0 ; i<m; i++)
    {
        cin >> a >> b;

        if( haa[b][a] > 0 )
        {
            z++;
            y++;
            haa[b][a]--;
            arr[b]--;

        }
        else
        {
            exta[x] = b;
            x++;
        }

    }

    for( i=0; i<x; i++)
    {
        if( arr[exta[i]]>0)
        {
            z++;
            arr[exta[i]]--;
        }
    }

    cout << z <<' ' << y;






}

