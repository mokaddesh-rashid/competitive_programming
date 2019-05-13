#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

#define sf scanf
#define pf printf

//set<int>::iterator ii;


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int i, j, x = 0, y = 1111, n, m, a;

    cin >> n ;

    for( i=0; i<n; i++)
    {
        cin >> a;
        x += a;
      if( a%2 != 0 )
         y = min( y , a);
    }

    if( x % 2 )
        cout << x;
    else
    {
        if( y == 1111 )
            cout << 0;
        else
            cout << x-y;
    }



    return 0;

}

