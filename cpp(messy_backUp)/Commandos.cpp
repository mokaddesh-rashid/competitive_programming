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
#define maxx          (long long) 1000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

LL mat[1001][1001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        cout << "Case " << ca++ << ": ";
        LL i, j, x, y, n, m, a, b, c, k, z;

        cin >> n >> m ;

        for( i=0; i<n; i++ )
            for( j=0; j<n; j++ )
                if( i != j ) mat[i][j] = maxx;

        for( i=0; i<m; i++ )
            {
                cin >> a >> b;
                c = 1;
                mat[a][b] = c,mat[b][a] = c;
            }

            for( k=0; k<n; k++ )
                for( i=0; i<n; i++ )
                    for( j=0; j<n; j++ )
            {
                 //cout << i << ' ' << k << ' ' << j << ' ' << mat[i][k]+mat[k][j] << endl;
                 if( mat[i][k]+mat[k][j] < mat[i][j] )
                 {
                     mat[i][j] = mat[i][k]+mat[k][j];
                 }
            }
            c = 0;
            cin >> a >> b;
            for( i=0; i<n; i++ )
            {
                c = max( c, mat[a][i]+mat[i][b] );

            }

            cout << c << endl;
    }

    return 0;

}



