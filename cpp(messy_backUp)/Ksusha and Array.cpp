
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int i, j, x = 0, y, n, m, a = 0;

    cin >> n ;

    int arr[n+1];

    for( i=0; i<n; i++)
    {
         cin >> arr[i];

         if( i == 0 )
            x = arr[i];
         else
            x = min( arr[i], x);
    }

    for( i=0; i<n; i++)
    {
        if( arr[i] % x )
             a = 1;

    }

    if( a == 0 )
        cout << x;
    else
        cout << -1;



    return 0;

}
