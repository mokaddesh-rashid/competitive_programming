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

int pa[100001], mp[100001];

int fi_pa( int x )
{

    if( pa[x] == x )
        return x;
    else
       {
          pa[x] = fi_pa( pa[x] );
          return pa[x];
       }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0, b, c = 0, d = 0;

    cin >> n >> m;

    for( i=1; i<=n; i++ )
    {
        pa[i] = i;
    }

    for( i=0; i<m; i++ )
    {
        cin >> a >> b;

        x = fi_pa(a);
        y = fi_pa(b);

        if( x == y )
            {
                c = 1;
            }
        else
        {
            mp[b] = a;
            pa[y] = x;
        }

    }

    for( i=1; i<=n; i++ )
    {
        x = fi_pa(i);
        cout << pa[i] << ' ';
        if( pa[i] == i )
            d++;
    }
    cout << endl;
    if( c == 1 && d == 1 )
        cout << "FHTAGN!";
    else
        cout << "NO";

    return 0;

}


