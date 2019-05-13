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

    long long int x = 1, a, b=1, c, n, d=0, i, l;

    cin >> n;

    for( i=0; i<n; i++)
    {
        cin >> a;


          if ( d == 1 && a == 1  )
        {
            //cout << 'h';
            x = x*c;
            c = 1;
        }
        else if( a == 1  )
        {
            d = 1;
            c = 1;
        }
        else if ( d == 1)
            c++;
       // cout << c << ' ';
    }
     if( d == 0 )
        cout << 0;
     else
        cout << x ;


    return 0;

}

