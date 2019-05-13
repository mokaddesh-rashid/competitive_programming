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
#define PB push_back
#define FF first
#define SS second
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


int damn[1001][1001];
int ar[10001], in[10001], out[10001];

struct node
{
    LL v, pa, l;
}bfa[100010];

vector<int> mat[100010];
int que[2000010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 1;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = p;
    r++;
    while( h != r )
    {
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( bfa[x].l < bfa[p].l+1 )
            {
                bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        h++;
        p = que[h];
    }

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, k;

    cin >> n >> k;


   for( i=0; i<k; i++ )
   {
       for( j=0; j<n; j++ )
        cin >> ar[j];

       for( j=0; j<n; j++ )
        for( int l=j+1; l<n; l++ )
            damn[ar[j]][ar[l]]++;


   }

    for( i=1; i<=n; i++ )
    {
            for( j=1; j<=n; j++ )
            {
                //cout << damn[i][j] << ' ' ;
                if( damn[i][j] == k )
                {
                    mat[i].PB( j );
                    in[j]++; out[i]++;
                }
            }

            //cout << endl;
    }

    for( i=1; i<=n; i++ )
    {
        if( in[i] == 0 )
        {
            bfs( i );
        }
    }

    x = 0;
    for( i=1; i<=n; i++ )
    {
        x  = max( x, bfa[i].l );
    }

    cout << x << endl;

    return 0;

}
/*
4 3
2 4 1 3
4 1 2 3
1 2 4 3
 */


