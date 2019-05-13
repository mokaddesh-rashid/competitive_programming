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


//set<int>::iterator ii;

struct node
{
    LL v, pa, l;
}bfa[100010];

vector<int> mat[100010];
int que[100010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = p;
    r++;
    while( h != r )
    {
        cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                cout << x << ' ';
                bfa[x].l = bfa[p].l;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        cout << endl;
        h++;
        p = que[h];
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

        mat[x].push_back( y );
        mat[y].push_back( x );
    }
    h =0;
    r = 0;
    bfs(1);

    return 0;

}


