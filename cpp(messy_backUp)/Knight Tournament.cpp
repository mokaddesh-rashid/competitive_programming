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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int s[3000011], ls[300011], ad[300011], pa[300011], v[300011], chk, n;

int f_s( int a )
{
    int i = 1, c;
    c = 0;
    while( s[i] <= a )
    {
        c += ls[i];
        i++;
    }
    if( i > 1 )
        i = s[i-1]+1;
////    cout << i << ' ' << c << endl;
    while( i<=a )
    {
        c += v[i];
        i++;
    }

    return c;
}

int f_i( int a )
{
    int i = 1, c;
    c = 0;
    while( c+ls[i] < a && i < chk )
    {
        //cout << i << ' ' << ls[i] << endl;

        c += ls[i];
        i++;
    }
    if( i > 1 )
        i = s[i-1]+1;
    //cout << i << ' ' << c << endl;
    while( c <= a && i <= n )
    {
        c += v[i];

        if( c < a )
             i++;
    }

    return i;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, m, a, b, c, d, e;

    cin >> n >> m ;

    c = sqrt(n);
    x = 1;
    a = 0;
    for( i=1; i<=n; i++ )
    {
        v[i] = 1;
        pa[i] = i;
        ad[i] = x;
        ls[x]++;
        s[x] = i;
        if( i%c == 0 )
            x++;
    }
    chk = x;
    s[x+1] = n+1;
    //cout << c << endl << x << endl;

    while(m--)
    {
        cin >> a >> b >> c;
        i = f_s(a-1)+1;
        //cout << i << endl;
        while( true )
        {
            x = f_i(i);
            //cout << i << ' ' << x << endl;
            if( x >=a && x <= b && x != c )
                {
                    pa[x] = c;
                    y = ad[x];
                    v[x] = 0;
                    ls[y]--;
                }
            else if( x != c )
                break;
            else
                i++;
        }
        //cout << f_i(a) << endl;
    }


    for( i=1; i<=n; i++ )
    {
        if( pa[i] == i )
            cout << 0 << ' ';
        else
            cout << pa[i] << ' ';
    }


    return 0;

}


