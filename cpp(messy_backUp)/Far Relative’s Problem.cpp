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

    long long int i, j, x =0 , y = 0, n, m, arr[5555] = {0}, brr[5555] = {0}, c, d = 0, a, b;

    char ch;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> ch;

        if( ch == 'M' )
        {
            cin >> a >> b;

            arr[a]++;
            arr[b+1]--;
        }
        else
        {
            cin >> a >> b;

            brr[a]++;
            brr[b+1]--;
        }
    }

    for( i=0; i<5005; i++)
    {
        x += arr[i];
        y += brr[i];

        c = min( x, y);

        d = max( c, d );
    }

    cout << d*2;

    return 0;

}
