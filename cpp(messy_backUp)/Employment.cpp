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

int mat[510][510], cnt[500], c, job[500], n;

void chk( int p, int lik )
{
    int e = job[lik];

    for( int i=1; i<=n; i++ )
    {
        if( mat[lik][i] == e ) return;
        else if( mat[lik][i] == p )
        {
            cnt[e] = 0;
            job[lik] = p;
            cnt[p] = lik;
            return;

        }
    }

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        memset( mat, 0, sizeof( mat ) );
        memset( cnt, 0, sizeof( cnt ) );
        memset( job, 0, sizeof( job ) );

        int i, j, x, y, m, a, b;

        c = 0;

        cin >> n;

        for( i=1; i<=n; i++ )
            for( j=1; j<=n; j++ )
                cin >> mat[i][j];

        for( i=n+1; i<=n+n; i++ )
            for( j=1; j<=n; j++ )
                    cin >> mat[i][j];

        c = 0;
        while( c < n )
        {
            for( i=1; i<=n; i++ )
            {
                a = mat[i][0]+1;

                if( cnt[i] == 0 && a <= n )
                    chk( i, mat[i][a] ), mat[i][0]++;
            }
            c++;
        }

        cout << "Case " << ca++ << ": ";
        for( i=1; i<=n; i++ )
            cout  << '(' << i << ' ' << cnt[i] << ')' << ' ';
        cout << endl;

    }

    return 0;

}

