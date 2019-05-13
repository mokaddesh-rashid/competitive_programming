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

    long long int i, j, x, y=0, n, m, a=0, b=0, minn = -1, z;

    cin >> n;

    for( i=0; i<n; i++)
    {
        cin >> x;

        y += x;

        if( x % 2 )
            {
                a++;

                if( minn == -1 )
                    minn = x;
                else
                    minn = min( x,minn);
            }

    }

    if( a%2 && a != 0 )
          y -= minn;

    cout << y;







    return 0;

}

