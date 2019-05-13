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

    long long int i, j, x = 1 , l, r, k, a=0, t=1;

    cin >> l >> r >> k;


    while( x >= t &&x <= r )
    {
        if( x >= l && x <= r )
           {
               if( x % k != 0 && x != 1)
                 break;
             cout << x << ' ';
             a = 1;
           }
        x *= k;
        t = max(t,x);
        if( x < t )
            break;
    }

    if( a == 0 )
        cout << -1;


    return 0;





}

