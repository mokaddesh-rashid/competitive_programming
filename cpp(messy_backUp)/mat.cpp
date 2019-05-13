#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

LL mat[500][500], ans[200200];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL t;

    cin >> t;

    while( t-- )
    {
        LL i, j, x, y, n, m, p, a, b;
        memset( ans, 0, sizeof(ans) );
        memset( mat, 0, sizeof(mat) );
        cin >> n ;

        m = 2*n;
        p = 1;
        for( i=1; i<=n; i++ )
        {
            p = (i-1)*n+1;
            for( j=1; j<=m; j++ )
            {
                mat[i][j] = p;
                mat[m-i+1][j] = p;
                if( j<n )
                    p++;
                if( j>n )
                    p--;
            }
        }

        for( i=1; i<=m; i++ )
        {
            for( j=1; j<=m; j++ )
            {
                cin >> b;a = mat[i][j];
                    ans[a] = max( ans[a], b );
                }

            //cout << endl;
        }
        x = 0;
        for( i=1; i<=m; i++ )
        {
            x += ans[i];
        }

        cout << x << endl;

    }





    return 0;

}


