#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

vector<LL> mat[MAX], lolo[MAX], mono[MAX];
LL n, val[MAX], lng[MAX], mina[MAX], prin;

LL dfs(LL p,LL pa)
{
    lng[p] = mina[p] = val[p];
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        dfs(x, p);

        lng[p] = max(lng[p], lng[x] + val[p]);
        mina[p] = max(mina[p], mina[x]);

        lolo[p].PB( lng[x] );
    }

    sort(lolo[p].begin(), lolo[p].end());
    reverse(lolo[p].begin(), lolo[p].end());

    if(lolo[p].size() > 1) mina[p] = max(mina[p], lolo[p][0] + val[p] + lolo[p][1]);
    if(lolo[p].size()) mina[p] = max(mina[p], lolo[p][0] + val[p]);
}

LL dfsV2(LL p,LL pa,LL up,LL dud)
{
    prin = max(prin, mina[p] + up);

    set<PR> sota, bota;
    set<PR>::iterator it;


    for(auto x : mat[p])
    {
        if(x == pa) continue;
        sota.insert( MP(lng[x], x) );
        bota.insert( MP(mina[x], x) );
    }

    bota.insert( MP(up, -1) );
    sota.insert( MP(dud, -1) );

    for(auto x : mat[p])
    {
        if(x == pa) continue;
        sota.erase( MP(lng[x], x) );
        bota.erase( MP(mina[x], x) );

        LL boa = val[p];

        it = sota.end(); it--;
        boa += it->F;

        if(sota.size() > 1)
        {
            it--;
            boa += it->F;
        }

        dfsV2(x, p, max(boa, bota.rbegin()->F), sota.rbegin()->F + val[p]);

        sota.insert( MP(lng[x], x) );
        bota.insert( MP(mina[x], x) );
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    LL x, y;

    cin >> n;
    FOR(i,1,n) cin >> val[i];
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB(y);
        mat[y].PB(x);
    }
    dfs(1, 1);
    dfsV2(1, 1, 0, 0);

    cout << prin << endl;

    return 0;
}

