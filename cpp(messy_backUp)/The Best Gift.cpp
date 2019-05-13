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

    long long int n, m, i, j, x=0, a, b , c, arr[111]={0};

    cin >> n >> m;

    for( i=0; i<n ;i++)
    {
        cin >> a;

        arr[a]++;
    }


    for( i=1; i<=m; i++)
    {
        for(j=i+1; j<=m; j++)
        {
            a= arr[i]*arr[j];
            x += a;
        }
    }

    cout << x;





}

