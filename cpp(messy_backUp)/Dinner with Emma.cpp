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

    long long int n, m;

    cin >> n >> m;

    int maxx=0, minn, i, j, a , b;

    for( i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
        {
            cin >> a;

           if( j == 0)
              b = a;
           else
              b = min(b,a);
        }

        maxx = max( b, maxx);
    }

    cout << maxx;



}

