#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define F first
#define S second
#define PB push_back
#define MAX 100010
typedef pair<int,int> P;

set<P> sota;
vector<int> mat[MAX];
int lev[MAX], pa[MAX], farcry, farchild[MAX], del[MAX];

int dfs(int p)
{
    int ret = p;

    FOR(i,0,(int)mat[p].size()-1)
    {
        int x = mat[p][i];

        if(pa[p] != x)
        {
            pa[x] = p;
            lev[x] = lev[p] + 1;

            int boo = dfs( x );
            if(lev[boo] > lev[ret]) ret = boo;

        }
    }

    return farchild[p] = ret;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int n, x, y;

    cin >> n;

    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }

    memset(lev, 0, sizeof(lev));
    memset(pa, 0, sizeof(pa));
    farcry = dfs( 1 );

    memset(lev, 0, sizeof(lev));
    memset(pa, 0, sizeof(pa));
    farcry = dfs( farcry );

    memset(lev, 0, sizeof(lev));
    memset(pa, 0, sizeof(pa));
    dfs( farcry );

    FOR(i,1,n)
    {
        sota.insert( make_pair(lev[ farchild[i] ] - lev[i] , farchild[i]) );
    }

    int c = 1; del[farcry] = 1;
    FOR(i,1,n)
    {
        cout << c << ' ';
        if(!sota.empty())
        {
            P use = *(sota.begin());
            sota.erase( sota.begin() );

            int p = use.S;
            while(p != 0)
            {
                if(del[p]) break;
                del[p] = 1;
                c++;
                p = pa[p];

            }

        }

    }



    return 0;
}
