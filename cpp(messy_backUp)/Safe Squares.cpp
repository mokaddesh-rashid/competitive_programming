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
typedef pair<int,int> p_i;


//set<int>::iterator ii;

int mat[3001][3001], n, m;

int chk( int x, int y )
{
    int st = 1, en = min(n-x, m-y), mid, c = 0, a, b, re = 0;

    while( st <= en )
    {
        a = 0;
        mid = (st+en)/2;
        for(int i=0; i<mid; i++ )
        {
            if( y != 0 ) b = mat[x+i][y-1];
            else b = 0;
            c = mat[x+i][y+mid-1];

            if( c-b > 0 ) a = 1;

        }
        if( a == 0 ) st = mid+1, re = max( re, mid );
        else en = mid-1;

    }
    return re;
}

int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        int i, j, x = 0, y, k, a = 0, b, c;
        memset( mat, 0, sizeof(mat) );
        cin >> n >> m >> k;

        for( i=0; i<k; i++ )
        {
            cin >> a >> b;
            mat[a][b]++;
        }
        for( i=0; i<n; i++, x = 0 )
            for( j=0; j<m; j++ )
        {
            x += mat[i][j];
            mat[i][j] = x;
        }
         a = 0;
        for( i=0; i<n; i++, x = 0 )
            for( j=0; j<m; j++ )
                a += chk( i, j );// cout << i << ' ' << j << ' ' << chk( i, j ) << endl;
        cout << "Case #" << ca++ << ": " << a << endl;

    }
    return 0;

}


