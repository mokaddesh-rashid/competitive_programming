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

    long long int n, l, r, q, t;

    cin >> n >> l >> r >> q >> t;

    long long int arr[n+1], x=0, y=0, z=0, a, b, c, d, i, l=0;

    a = n/2;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];

        l += arr[i];

        if( i < a )
        {
            x = x + (arr[i]*l);
        }
        else if( i == a && n % 2)
        {
            x = x + min((arr[i]*l),arr[i]*r);
        }
        else
        {
            x = x + (arr[i]*r);
        }
    }
    a = 0;
    for( i=0; i<n; i++,a++)
    {
        if( i == 0 )
           y = y + arr[i]*l;
       else
           y = y + arr[i]*l +q;
    }
    a = 0;
    for( i=n-1; i>=0; i--,a++)
    {
        if( i==n-1 )
            z = z + arr[i]*r;
        else
            z = z + arr[i]*r + t;
    }

    a = min(x,y);
    a = min(a,z);





}

