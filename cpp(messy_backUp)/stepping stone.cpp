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
    LL v, pa, l;
}dfa[100010];

vector<int> mat[100010];
int t;

void dfs( int p , int v )
{
    if( v <= 30 )
    {
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
                //cout << p << ' ' << x << endl;
                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs( x, v*10+x );
        }

        cout << v << ' ';
    }
}

void con( int a, int b )
{
    mat[a].push_back( b );
    mat[b].push_back( a );
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    for( int i=0; i<9; i++ )
       con( i, i+1 );

    int i, j, x, y, n, m;

    for( i=1; i<10; i++ )
    {
        memset( dfa, 0, sizeof( dfa ) );
        dfs( i, i );
        cout << endl;
    }





    return 0;

}



