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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
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

    int i, j, x, y, n, m = 0, a, b, c, d;

    cin >> n ;

    for( i=0; i<n; i++ )
    {
        cin >> a;

        if( a == 1 )
            x = i+1;
        else if( a == n )
            y = i+1;

    }

    b = max( 1 - x , x - 1 );
    m = max( b, m );
    b = max( 1 - y , y - 1 );
    m = max( b, m );
    b = max( n - x , x - n );
    m = max( b, m );
    b = max( n - y , y - n );
    m = max( b, m );

    cout << m;





    return 0;

}


