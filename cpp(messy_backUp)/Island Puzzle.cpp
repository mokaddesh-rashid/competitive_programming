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

    int n;

    cin >> n;

    int arr[n+1], brr[n+1], i, j , x=0, y=0, a, b, d = 0 ,c, t = 0;

    for( i=0; i<n; i++)
    {
        cin >> a;

        if( a != 0 )
        {
            if( a == 1 )
                b = x;
            arr[x] = a;
            x++;
        }
    }

    for( i=0; i<n; i++)
    {
        cin >> a;

        if( a != 0 )
        {
            if( a == 1 )
                c = y;
            brr[y] = a;
            y++;
        }
    }

    while( d < n-1 )
    {
        //cout << b << ' ' << c << endl;
        if( arr[b] != brr[c] )
        {
            t = 1;
        }
        d++;
        b++;
        c++;
        b %= (n-1);
        c %= (n-1);
    }

    if( t == 0 )
        cout << "YES";
    else
        cout << "NO";

    return 0;

}

