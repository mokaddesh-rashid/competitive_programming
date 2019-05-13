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

    int arr[1000000+1] = {0}, prime[1000000+1] = {0}, x=0, i, j, t, y, a, b;

    for( i=2; i<1000000+1; i++)
    {
        if( arr[i] == 0 )
        {
            x++;
            j = i+i;
            while( j < 1000000+1 )
            {
                arr[j] = 1;
                j += i;
            }
        }
        prime[i] = x;
    }

    cin >> t;

    while( t-- )
    {
        cin >> x >> y;

        a = min(x,y);
        b = max(x,y);

        cout << prime[b] - prime[a-1] << endl;
    }







}

