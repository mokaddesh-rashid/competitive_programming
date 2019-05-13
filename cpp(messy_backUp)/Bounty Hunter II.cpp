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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int ind[10001], oud[10001], dp[1010][1010], vis[10001];
vector<int> mat[1010];

int rec( int x, int y )
{
    int i, j;
    if( vis[x] == 1 )
        return 0;
    if( ind[x] == 0 && oud[x] == 0 )
        return 1;
    if( mat[x][0] == 0 )
        return 0;
    if( y == 0 )
    {
        for( i=1; i<=mat[x][0]; i++ )
        {
            int temp ;
            cout << mat[x][i] << ' ';
            temp = 1+rec( mat[x][i], 1 );
            for( j=1; j<=mat[x][0]; i++ )
            {
                cout << mat[x][j] << ' ';
                if( i != j )
                    temp += rec( mat[x][j], 0 );
            }
            cout << endl;
            if( i == 1 )
                dp[x][y] = temp;
            else
                dp[x][y] = min( dp[x][y], temp );
        }
        for( i=1; i<=mat[x][0]; i++ )
            vis[mat[x][i]] = 1;
        return dp[x][y];
    }
    if( y == 1 )
    {

        for( i=1; i<=mat[x][0]; i++ )
        {
            cout << mat[x][i] << ' ';
            int temp ;
            temp = rec( mat[x][i], 1 );
            for( j=1; j<=mat[x][0]; i++ )
            {
                cout << mat[x][j] << ' ';
                if( i != j )
                    temp += rec( mat[x][j], 0 );
            }
            cout << endl;
            if( i == 1 )
                dp[x][y] = temp;
            else
                dp[x][y] = min( dp[x][y], temp );
        }
        for( i=1; i<=mat[x][0]; i++ )
            vis[mat[x][i]] = 1;
        return dp[x][y];
    }
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, k, a, b, c, y, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> k;
        mat[i].push_back(k);
        for( j=0; j<k; j++ )
        {
            cin >> b;
            oud[i]++;
            ind[b]++;
            mat[i].push_back(b);
        }
    }

    for( i=0; i<n; i++ )
    {
        if(ind[i] == 0 )
        {
            x += rec(i,0);
        }
    }

    cout << x << endl;





    return 0;

}


