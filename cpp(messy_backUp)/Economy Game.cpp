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
#define NL '\n'


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, z, a, b, c, d, cnt;

    cnt = x = y = 0;

    cin >> n ;

    a =  1234567;
    b =  123456;
    c =  1234;

    while( x <= n )
    {
        y = 0;
        while( x + y <= n )
        {
            //cout << x << ' ' << y << endl;
            if( ( ( n - x - y ) % c == 0 ) && ( n - x - y ) >= 0 )
                cnt = 1;
            y += b;
        }
        x += a;
    }

    if( cnt == 1 )
        cout << "YES";
    else
        cout << "NO";




    return 0;

}


