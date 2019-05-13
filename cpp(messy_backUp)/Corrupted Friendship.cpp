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
    LL v, pa, l, st, en;
}dfa[100010];

vector<int> mat[100010];
LL cnt, ar[100010], pos;

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        dfa[p].st = cnt, cnt++;
        ar[pos] = cnt-1, pos++;
        //cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs(x);
            }
        }
        //cout << p << ' ';
        dfa[p].en = cnt, cnt++;
    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL t, ca = 1;

    cin >> t;

    while( t-- )
    {
        LL i, j, x, y, n, m, a, b, c;
        a = pos = cnt  = 0;

        cin >> n;

        for( i=0; i<=n; i++ )
            mat[i].clear();

        for( i=1; i<n; i++ )
        {
            cin >> x >> y;

            mat[x].push_back( y );
            //mat[y].push_back( x );
        }
        memset( dfa, 0, sizeof( dfa ) );
        dfs(1);
        for( i=1; i<=n; i++ )
            {
                x = dfa[i].en;
                j = upper_bound( ar, ar+pos, x ) - ar;
                if( dfa[i].en != 0 ) a += (n-j);

            }

        cout << "Case " << ca++ << ": " << n-1 << ' ' << a << endl;
    }

    return 0;

}





