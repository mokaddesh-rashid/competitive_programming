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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

struct node
{
    LL v, pa, l, f;
}dfa[100010];

vector<int> mat[100010], cost[100010];

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                dfa[x].l = dfa[p].l + cost[p][i];
                dfa[x].pa = p;
                dfs(x);
                dfa[p].f = max( dfa[p].f, dfa[x].f+cost[p][i] );
            }

        }
        //cout << endl;
        ///cout << p << ' ';
    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        memset( dfa, 0, sizeof(dfa) );
        int i, j, x, y, n, m, z, a, b, c, d, p;

        cin >> n ;

        for( i=0; i<=n; i++ )
           mat[i].clear(), cost[i].clear();

        for( i=0; i<n-1; i++ )
        {
            cin >> x >> y >> z;
            x++, y++;
            //cout << x << ' ' << y << endl;
            mat[x].push_back(y);
            mat[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        dfs(1);

        x = dfa[1].f;

        for( j=1; j<=n; j++ )
        {
            c = d = 0;
            for( i=0; i<mat[j].size(); i++ )
            {
                a = mat[j][i];
                b = dfa[a].f+cost[j][i];
                //cout << j << ' ' <<' ' << a << ' ' << b << endl;
                if( c < b && dfa[a].pa == j ) p = i, c = b;
            }

            for( i=0; i<mat[j].size(); i++ )
            {

                a = mat[j][i];
                b = dfa[a].f+cost[j][i];
                //cout << j << ' ' << i << ' ' << a << ' ' << b << endl;
                if( i != p && d < b && dfa[a].pa == j ) d = b;
            }
            // cout << j << ' ' << c << ' ' << d << endl;
            c = c+d;
            x = max( x, c );
        }
        cout << "Case " << ca++ << ": ";
        cout << x << endl;
    }

    return 0;

}


