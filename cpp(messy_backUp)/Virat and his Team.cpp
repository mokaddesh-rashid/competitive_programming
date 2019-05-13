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

    long long int i, j, x, y=0, n, m, arr[1000000+5] = {0};

    cin >> n;



    for( i=2; i <= n/2; i++)
    {
        if( arr[i] == 0 )
        {
            j = i+i;
            while( j <= n )
            {
                arr[j] = i;

                j += i;
            }
        }
    }

    while( n > 0 )
    {
        //cout << n << endl;
        if( arr[n] == 0 )
        {
            y++;
            break;
        }
        else
        {
            y++;
            n -= arr[n];
        }


    }


    cout << y;

    return 0;

}

