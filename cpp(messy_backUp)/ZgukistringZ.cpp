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

LL ar[1001], br[1001], cr[1001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    string a, b, c;
    LL i, j, x, y, n, m, z, d, e, f;

    cin >> a >> b >> c ;

    n = a.size();

    for( i=0; i<n; i++)
    {
        x = a[i]-97;
        ar[x]++;
    }

    n = b.size();

    for( i=0; i<n; i++)
    {
        x = b[i]-97;
        br[x]++;
    }



    n = c.size();

    for( i=0; i<n; i++)
    {
        x = c[i]-97;
        cr[x]++;
    }

    x = mx;
    y = mx;
    d = 0;
    for( i=0; i<26; i++)
    {
        //if( ar[i] < br[i] )
           // d = 1;
        if( br[i] > 0 )
            x = min( x, (ar[i]/br[i]) );
    }

    //if( d == 1 )
        //x = 0;

    //d = 0;
    for( i=0; i<26; i++)
    {
        z = ar[i] - (br[i]*x);
        //if( z < cr[i] )
            //d = 1;
        if( cr[i] > 0 )
            y = min( y, (z/cr[i]) );
    }

    //if( d == 1 )
        //y = 0;

    //cout << x << ' ' << y << endl;
    e = x+y;
    return 0;

}

