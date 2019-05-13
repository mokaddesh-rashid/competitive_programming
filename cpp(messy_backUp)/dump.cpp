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
typedef pair<int,int> PR;

int paa[MAX], n, id[MAX], sz[MAX], popo[MAX], vis[MAX];
vector<PR> mat[MAX];
pair<int,PR> in[MAX];

int finPa(int p)
{
    return (paa[p] == p) ? p : (paa[p] = finPa( p ));
}

int dfs(int p,int pa,int v)
{
    cout << "in" << endl;
    vis[p] = popo[p] = 1;
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;
        if(x.S == v)
        {
            dfs(x.F, p, v);
            popo[p] += popo[x.F];
        }
        else
        {
            int r1 = finPa( x.F );
            popo[p] += sz[r1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int x, y, c;
    FOR(i,1,MAX-1) id[i] = paa[i] = i, sz[i] = 1;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> x >> y >> c; in[i].F = c;
        in[i].S.F = x; in[i].S.S = y;

        mat[x].PB(MP(y, c));
        mat[y].PB(MP(x, c));
    }

    sort(id + 1, id + n, [](int a,int b)
         {
             return in[a].F < in[b].F;
         });

    int p = 1, q;

    FOR(i,1,n-1)
    {
        FOR(j,p,n-1)
        {
            if(in[ id[p] ].F == in[ id[j] ].F)
            {
                if(!vis[ in[ id[j] ].S.F ])
                    dfs(in[ id[j] ].S.F, in[ id[j] ].S.F, in[ id[j] ].F);
            }
            else
            {
                q = j;
                break;
            }
        }
        FOR(j,p,q-1)
        {
            int r1 = finPa( in[ id[j] ].S.F ), r2 = finPa( in[ id[j] ].S.S );

            if(r1 != r2)
            {
                paa[r2] = r1;
                sz[r1] += sz[r2];
            }
        }

        p = q;

        x = in[ id[i] ].S.F; y = in[ id[i] ].S.S;
        int r1 = finPa( x ), r2 = finPa( y );

        if(popo[x] > popo[y]) swap(x, y);

        int v = sz[r1], va = popo[x];
        v -= va;
        cout << id[i] << ' ' << x  << ' ' << y << ' ' << v * va << endl;

    }

    return 0;
}

