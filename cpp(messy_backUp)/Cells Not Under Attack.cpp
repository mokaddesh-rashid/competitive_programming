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

int col[1000011], row[1000011];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, z, a, b, c = 0, r = 0;

    cin >> n >> m ;

    z = n*n;
    //cout << z << endl;
    for( i=0; i<m; i++ )
    {
        cin >> a >> b;

        if( row[a] == 0 )
        {
            y = n-c;
            z =z-y;
            r++;
            row[a]++;
            //cout << y << ' ' << r << endl;
        }
        if( col[b] == 0 )
        {
            y = n-r;
            z = z-y;
            c++;
            col[b]++;
           // cout << y << ' ' << r << endl;
        }

        cout << z << ' ';
    }





    return 0;

}


