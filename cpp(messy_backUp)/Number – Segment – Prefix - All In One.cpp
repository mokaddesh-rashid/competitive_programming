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

    int ca;

    cin >> ca;

    while( ca-- )
    {
        long long int i, j, x = 1, y = 0, n, m, t;

    string str, sss, chk;

    cin >> str ;

    cin >> sss ;

     cin >> t;

    while( t-- )
    {

     x = 1;

     cin >> chk;

    n = chk.size();

    if( sss.size() >= chk.size() )
    {
        for( i=0; i<n; i++ )
    {
        if( str[i] <= chk[i] && sss[i] > chk[i] )
        {
            break;
        }

        else if( str[i] > chk[i])
        {
            x = 0;
            break;
        }
        else if( sss[i] < chk[i])
        {
            x = 0;
            break;
        }

    }

    }

    else
        x = 0;

    if( x == 1 )
        cout << 1;

    else
        cout << x;

    cout << endl;

    }


    }


    return 0;

}

