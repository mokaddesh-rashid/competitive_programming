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
    LL v, pa, l, c, d;
}dfa[100010];

vector<int> mat[100010], cst[100010];

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        //cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i], y = cst[p][i], mx = 0;
            if( dfa[x].v == 0 )
            {
                if( y == 1 )
                    dfa[x].c = 1;
                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs(x); ///call dfs
                dfa[p].d = max( dfa[p].d, dfa[x].d );
                if( dfa[x].c == 1 )
                    dfa[p].d = 1;
                if( dfa[p].d == 1 )
                    dfa[p].c = 0;

            }

        }
        //cout << p << ' ';
       // cout << p << ' ' << dfa[p].d << endl;
    }

}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, z, t = 0;

    cin >> n;

    for( i=1; i<n; i++ )
    {
        cin >> x >> y >> z;
        z--;
        mat[x].push_back( y );
        cst[x].push_back( z );
        mat[y].push_back( x );
        cst[y].push_back( z );
    }

    dfs(1);

   for( i=1; i<=n; i++ )
   {
       t += dfa[i].c;// << ' ';
   }
   cout << t << endl;
   for( i=1; i<=n; i++ )
   {
       if( dfa[i].c == 1 )
         cout << i << ' ';// << ' ';
   }



    return 0;

}


