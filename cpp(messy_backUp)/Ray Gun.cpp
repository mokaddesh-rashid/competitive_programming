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


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0, b;

    cin >> n >> m ;

    x = m;
    y = 0;

    for( i=0; i <= n; i++ )
    {
      a += __gcd( x, i );
    }

    x = m;

    for( i=0; i < m; i++ )
    {
      a += __gcd( x, i );
    }

    cout << a << endl;

    //b =  ( (n+1) * (m+1) ) - a;

    //cout << b+n+m;

    return 0;

}


