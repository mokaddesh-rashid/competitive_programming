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
    int v, pa, l;
}dfa[110];

vector<int> mat[110];
int v;

void dfs( int p )
{
    dfa[p].v = v+1;
    //cout << p << '(' << dfa[p].l << ')' << ' ';
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == v )
        {
            if( dfa[p].l == 0 )
                dfa[x].l = 1;
            if( dfa[p].l == 2 )
                dfa[x].l = 2;
            dfa[x].pa = p;
            dfs(x);
        }
        else if( dfa[p].l ==  dfa[x].l )
            dfa[x].l = 2;
        else if( dfa[p].l == 1 && dfa[dfa[x].pa].l == 0 )
            dfa[dfa[x].pa].l = 2;
        if( dfa[x].l == 2 )
                dfa[p].l = 2;
    }
    //cout << p << '(' << dfa[p].l << ')' << ' ';
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
        int i, j, x = 0, y, n, m;

        cin >> n >> m;
        for( i=0; i<101; i++ ) mat[i].clear();
        for( i=0; i<m; i++ )
        {
            cin >> x >> y;

            mat[x].push_back( y );
            mat[y].push_back( x );
        }
        memset( dfa, 0, sizeof(dfa) );
        if( mat[1].size() != 0 )
        dfa[1].l = 1;
        dfs( 1 );// cout << endl;
        dfs( 1 );
        dfs( 1 );

        x = 0;
         for( i=1; i<=n; i++ )
            x += min( 1, dfa[i].l );
         //if( ca == 90 ) cout << n << ' ' << m << endl;
         cout << "Case " << ca++ << ": " << x << endl;
    }

    return 0;

}



