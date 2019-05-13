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

    long double i, j, x, y, n, m, st, en, mid;


    cin >> n ;

    st = 0;

    en = n;

    mid = n;

    while( max (mid*mid - n , n - mid*mid ) < .0004 )
    {
        mid = ( st + en ) / 2;

        if( mid*mid > n )
            en = mid;
        else
            st = mid;
    }

    cout << mid;



    return 0;

}

