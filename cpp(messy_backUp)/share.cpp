#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i = j; i <= k; i++)
#define MAX 1005
#define F first
#define S second
#define PB push_back
typedef pair<int,int> PR;

vector<int> mat[MAX];
int dp[MAX], bm[MAX], l, v, n, T;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> T; FOR(i,0,T) mat[i].PB( 0 );
    FOR(i,0,n-1)
    {
        cin >> l >> v;
        l = T - l; mat[l].push_back( v );
    }
    FOR(p,0,T)
    {
        sort(mat[p].begin() + 1, mat[p].end());
        reverse(mat[p].begin() + 1, mat[p].end());

        for(int i = 1; i < (int)mat[p].size(); i++)
            mat[p][i] += mat[p][i - 1];
    }

    int np;
    for(int lev = T; lev > 0; lev--)
    {
        FOR(i,0,n)
            FOR(j,0,n)
            {
                if(i + j > n || j == mat[lev].size()) break;

                np = (i + j)>>1; if((i + j) % 2) np++;
                bm[np] = max(bm[np], dp[i] + mat[lev][j]);
            }

        FOR(i,0,n)
        {
            dp[i] = bm[i];
            bm[i] = 0;
        }
    }

    if(mat[0].size() > 1) dp[1] = max(mat[0][1], dp[1]);
    cout << dp[1] << endl;

    return 0;
}
