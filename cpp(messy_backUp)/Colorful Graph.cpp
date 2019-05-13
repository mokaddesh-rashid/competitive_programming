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

vector<int> fuck[100010];
vector<int> mat[100010];
int col[100010], cnt[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, z, a = 100010, b, c, mx = -1;

    cin >> n >> m ;

    for( i=1; i<=n; i++ )
    {
        cin >> x;
        a = min( a, x );
        col[i] = x;
        fuck[x].PB( i );
    }

    for( i=1; i<=m; i++ )
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }

    for( i=1; i<=100000; i++ )
   {
        c = 0;
        for( j=0; j<fuck[i].size(); j++ )
        {
            int p = fuck[i][j];
            //cout << i << ' ' << p << endl;
            for( int k=0; k<mat[p].size(); k++ )
            {
               x =  mat[p][k];
               y = col[x];
               //cout << x << ' ' << y << ' ' << 'c' << endl;
               if( cnt[y] == 0 && col[x] != col[p] )
               {
                   c++;
                   cnt[y] = 1;
               }
            }
        }
        for( j=0; j<fuck[i].size(); j++ )
        {
            int p = fuck[i][j];

            for( int k=0; k<mat[p].size(); k++ )
            {
               x =  mat[p][k];
               y = col[x];
               cnt[y] = 0;
            }
        }
        if( c > mx && c != 0 )
        {
            mx = c;
            a = i;
        }
   }

    cout << a << endl;

    return 0;

}
/*
3 1
13 13 4
1 2
*/

