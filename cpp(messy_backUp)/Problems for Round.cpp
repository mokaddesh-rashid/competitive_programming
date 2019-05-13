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

int div1[1000010], div2[1000010], use[1000010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c = 0, cnt = 0, maxx = -1, minn = -1;

    cin >> n >> m ;

    for( i=0; i<m; i++ )
    {
        cin >> a >> b;

        x = min( a, b );
        y = max( a, b );

        div1[y]++;
        div2[x]++;
        if( div1[y] > 0 && div2[y] > 0 )
            c = 1;
        if( div1[x] > 0 && div2[x] > 0 )
            c = 1;

    }

    for( i=1; i<=n; i++ )
    {
        if( div2[i] != 0 )
            maxx = i;
        if( div1[i] != 0 && minn == - 1 )
            minn = i;
    }

    if( ( c == 1 || maxx >= minn ) && ( minn != -1 ) )
        cout << 0;
    else
    {
        a = minn - maxx - 1;
        if( minn == -1 && maxx == -1 )
        {
            a = n-2;
        }

        a = max( 0, a );

        cout << a+1;

    }


    return 0;

}


