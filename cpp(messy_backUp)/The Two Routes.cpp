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
}bfa[100010], bus[100010];

vector<int> mat[1000], mt[1000];
int que[100010], h, r, con[500][500], use[500];

void bfs( int p )
{
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                //cout << x << ' ';
                bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        //cout << endl;
        h++;
        p = que[h];
    }

}

void bfss( int p )
{
    bus[p].l = 0;
    bus[p].pa = -1;
    bus[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(int i=0; i<mt[p].size(); i++ )
        {
            int x = mt[p][i];
            if( bus[x].v == 0 )
            {
                //cout << x << ' ';
                bus[x].l = bus[p].l+1;
                if(bfa[x].l == bus[x].l && use[x] == 1 ) bus[x].l++;
                bus[x].pa = p;
                bus[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        //cout << endl;
        h++;
        p = que[h];
    }

}

void path( int x )
{
    while( x != 1 )
    {
        use[x]++;
        x = bfa[x].pa;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;

    cin >> n >> m;

    for( i=0; i<m; i++ )
    {
        cin >> x >> y;
        con[x][y]++;
        con[y][x]++;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }
    r = h = 0;
    bfs(1);
    if( bfa[n].l != 0 ) path(bfa[n].pa);

    for( i=1; i<=n; i++ )
    {
        for( j=1; j<=n; j++ )
        {
            if( i != j && con[i][j] == 0 )
                mt[i].push_back(j), mt[j].push_back(i);
        }
    }
    r = h = 0;
    bfss(1);

    if( min( bfa[n].l, bus[n].l ) == 0 ) cout << -1 << endl;
    else cout <<  max( bfa[n].l, bus[n].l ) << endl;
    return 0;

}



