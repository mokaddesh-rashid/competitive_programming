#include<bits/stdc++.h>

using namespace std;

#define LL unsigned long long
#define PB push_back
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX 1000010

int pa[MAX], n, val[MAX], pos[MAX], can[MAX], sz[MAX];
vector<int> mat[MAX];

int finPa(int p)
{
    return (pa[p] == p) ? p : ( pa[p] = finPa(pa[p]) );
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int a, b, x, y, p;
    LL prin = 0;

    cin >> n;
    FOR(i,1,n) cin >> val[i];
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }

    FOR(i,1,n) pos[i] = i;
    sort(pos + 1, pos + n + 1, [](int a,int b){
            return val[a] < val[b];
         });

    memset(can, 0, sizeof(can));
    memset(sz, 0, sizeof(sz));
    FOR(i,1,MAX-1) pa[i] = i;

    FOR(i,1,n)
    {
        p = pos[i];
        sz[p] = can[p] = 1;
        for(auto x : mat[p])
        {
            if(!can[x]) continue;
            int r1 = finPa( p ), r2 = finPa( x );

            LL c = (LL)sz[r1] * sz[r2];
            prin += (LL)c * val[p];

            sz[r1] += sz[r2];
            pa[r2] = r1;
        }
    }
    ///cout << prin << endl;
    FOR(i,1,n) pos[i] = i;
    sort(pos + 1, pos + n + 1, [](int a,int b){
            return val[a] > val[b];
         });

    memset(can, 0, sizeof(can));
    memset(sz, 0, sizeof(sz));
    FOR(i,1,MAX-1) pa[i] = i;

    FOR(i,1,n)
    {
        p = pos[i];
        sz[p] = can[p] = 1;
        for(auto x : mat[p])
        {
            if(!can[x]) continue;
            int r1 = finPa( p ), r2 = finPa( x );

            LL c = (LL)sz[r1] * sz[r2];
            prin -= (LL)c * val[p];

            sz[r1] += sz[r2];
            pa[r2] = r1;
        }
    }

    cout << prin << endl;

    return 0;
}
