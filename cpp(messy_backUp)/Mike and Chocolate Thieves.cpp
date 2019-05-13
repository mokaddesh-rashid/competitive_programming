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
LL m, c;

int chk( LL n )
{
    LL i, j, a, b;
    c = 0;
    for( i=2; i*i*i<= n; i++ )
    {
        a = i*i*i;
        b = n/a;
        c += b;
    }

    if( c >= m )
        return 1;
    else
        return 0;

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, st, en, mid, j, x = 0 , y = 0, n, maxx = mx, a, b = (LL)10000000000000000;

    cin >> m;

    st = 0;
    en = b;


    while( st <= en )
    {
        mid = ( st+en ) / 2;

        a = chk( mid );

        if( a == 1 )
        {
            if( c == m )
                maxx = min( maxx, mid );

            en = mid-1;
        }

        else
            st = mid+1;
    }

  if( maxx == mx )
    cout << -1;
  else
   cout << maxx << endl;


    return 0;

}

