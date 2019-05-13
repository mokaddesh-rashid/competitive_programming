#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define MOD          998244353
#define PB push_back
#define MAX 200010


struct Node
{
    int ex, mini;
    int pref[335];
};
Node block[335];
vector<int> posi[MAX];
int n, k, ara[MAX], val[MAX], dp[MAX];
int blockSz;

int which(int p) { return (p/blockSz); }

void add(int &a,int b)
{
    a += b;
    if(a >= MOD) a -= MOD;
}

void calDp(int bi)
{
    int first = max(1, blockSz * bi), last = blockSz * (bi + 1) - 1;
    int mini, &ex = block[ bi ].ex;

    FOR(i,first,last) val[i] += ex;
    mini = INT_MAX; ex = 0;

    FOR(i,first,last) mini = min(val[i], mini);
    FOR(i,first,last) val[i] -=  mini;
    ex = mini; mini = 0;


    memset( block[ bi ].pref, 0, sizeof(  block[ bi ].pref ) );
    FOR(i,first,last)
        add(block[ bi ].pref[ val[i] ], dp[i - 1]);
    FOR(i,1,blockSz)
        add(block[ bi ].pref[ i ], block[ bi ].pref[ i - 1 ]);

}

void update(int l,int r,int v)
{
    FOR(i,l,r)
    {
        int blockId = which( i ), first = blockSz * blockId, last = blockSz * (blockId + 1) - 1;

        if(l <= first && last <= r) block[ blockId ].ex += v, i = last;
        else val[i] += v;
    }

    calDp( which( l ) );
    calDp( which( r ) );
}

int main()
{
    ios::sync_with_stdio(false);
   // inf;
    //outf;
    int v;

    cin >> n >> k; blockSz = sqrt( n ) + 1;
    FOR(i,0,MAX-1) posi[i].PB( 0 );

    dp[0] = 1;
    FOR(i,1,n)
    {
        cin >> v;

        int p = (int)posi[v].size() - 1;
        if(posi[v].size() >= 2) update(posi[v][p - 1] + 1, posi[v][p], -1);
        posi[v].PB( i );

        p = (int)posi[v].size() - 1;
        update(posi[v][p - 1] + 1, posi[v][p], 1);

        dp[i] = 0;
        int til = which( i );

        FOR(bi,0,til)
        {
            int can = k - block[bi].ex;
            if(can >= 0) add(dp[i], block[bi].pref[ min(blockSz, can) ]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}

