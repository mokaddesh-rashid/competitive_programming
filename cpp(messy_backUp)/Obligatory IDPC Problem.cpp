o#include<iostream>
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



    unsigned long long int i, j, x = 1, y,  m, arr[100], t ;

    for( i=1; i<=2*10; i++)
    {
       x *= i;

       arr[i] = x;
    }

    cin >> t ;

    while( t-- )
    {
        cin >> n;

        x = arr[n*2];

        for( i=0; i<n; i++ )
        {
            x = x / arr[2];
        }

        cout << x << endl;
    }



    return 0;

}
