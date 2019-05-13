#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i = 1, j, x, y, n, m, a, b, z;

    cin >> n >> m ;

    LL arr[ n + 11 ];

    for( i=1; i<=n; i++ )
    {
        cin >> arr[i];
    }
    x = 1;
    while( true )
    {
        a = x * ( x + 1 );
        a /= 2;
        if( a >= m )
            break;
        else
            x++;
    }

    x--;

    y = x * ( x + 1 );
    y /= 2;

    z = m - y;

    cout << arr[z];





    return 0;

}


