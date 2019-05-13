#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

struct node
{
    LL v, pa, l;
}dfa[100010];

vector<int> mat[100010], cost[100100];
int stk[100010], top;

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        //cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                dfa[x].l = dfa[p].l+cost[p][i];
                dfa[x].pa = p;
                dfs(x);
            }
        }
        stk[++top] = p;

    }
}


void up()
{
    int i, j, x, p, y;

    REV( i, top, 0 )
    {
        p = stk[i];
        y = mat[p].size()-1;
        FOR( j, 0, y )
        {
            x = mat[p][j];
            if( p == 6 && x == 5 )
                cout << dfa[x].l << ' ' << dfa[p].l <<  ' ' << cost[p][j] << endl;
            if( dfa[x].l < dfa[p].l+cost[p][j] )
                dfa[x].l = dfa[p].l+cost[p][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, z, a, b, c;

    cin >> n >> m;

    for( i=0; i<m; i++ )
    {
        cin >> x >> y;
        z = 1;
        mat[x].push_back( y );
        cost[x].push_back( 1 );
    }
    top = -1;
    dfs(1);

    up();

    cout << endl << dfa[9].l << endl;

    return 0;

}



