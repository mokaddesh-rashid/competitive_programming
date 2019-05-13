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

int l, d;

struct node
{
    LL v, pa, l;
}dfa[100010];

vector<int> mat[100010];
int ar[100][100], dp[100][100];

int dfs( int p , int v )
{

    if( l == v && p == d ) return 1;
    if( l < v ) return 0;
    if( dp[p][v] != -1 ) return dp[p][v];

    int temp = 0;

    for(int i=0; i<mat[p].size(); i++ )
    {
            int x = mat[p][i];
            temp += dfs( x, v+1 );
    }

    return dp[p][v] = temp;
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t;

    cin >> t;

    while( t-- )
    {
        memset( dp, -1, sizeof( dp ) );
        memset( dfa, 0, sizeof( dfa ) );
        int i, j, x, y, n, m, a;

        cin >> n;
        for( i=0; i<n; i++ )
            mat[i].clear( );

        for( i=0; i<n; i++ )
            for( j=0; j<n; j++ )
        {
            cin >> a;
            ar[i][j] = a;
            if( a == 1 )
            {
                x = i, y = j;
                mat[x].push_back( y );
                //mat[y].push_back( x );
            }
        }


            cin >> x >> d >> l;

            cout << dfs( x , 0 ) << endl;
    }



    return 0;

}



