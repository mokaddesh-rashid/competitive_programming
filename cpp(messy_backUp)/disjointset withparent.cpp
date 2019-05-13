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

int pa[200001],mp[200001];

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

    int i, j, x, y, n, m, a, b,cnt = 0, rt = -1;

    cin >> n ;

    for( i=1; i<=n; i++ )
    {
        pa[i] = i;
        mp[i] = i;
    }

    for( i=0; i<n; i++ )
    {
        cin >> a;
        b = i+1;
        x = fi_pa(a);
        y = fi_pa(b);

        if( x == y )
            {
                if( a == i+1 && rt == -1 )
                    rt = b;
                mp[b] = -1;
                cnt++;
            }//cout << "they are connected\n";
        else
        {
            mp[b] = a;
            pa[y] = x;
        }
    }
    if( rt == -1 )
    {
        cnt++;
    }

    cout << cnt-1 << endl;

    for( i=1; i<=n; i++ )
    {
        if( mp[i] == -1 && rt == -1 )
        {
            rt = i;
        }
        if( mp[i] == -1 )
            cout << rt << ' ';
        else
            cout << mp[i] << ' ';
    }

    return 0;

}



