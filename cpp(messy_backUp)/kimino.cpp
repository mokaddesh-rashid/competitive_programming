
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
#define en first
#define st second
#define MAX 1505
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pii;

map<int,int> mopa;

int getId(int v)
{
    if(!mopa[v]) mopa[v] = mopa.size();
    return mopa[v];
}

int fuck[MAX], n;
vector<pii> mat[MAX*MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1) cin >> fuck[i];

    FOR(i,0,n-1)
    {
        int c = 0;
        FOR(j,i,n-1)
        {
            c += fuck[j];
            int iii = getId( c );
            mat[iii].PB( {j, i} );
        }
    }

    int sz = mopa.size(), prin = 0, popo;

    FOR(p,1,sz)
    {
        sort(mat[p].begin(), mat[p].end());
        int lp = 0, c = 0;

        for(auto x : mat[p])
            if(x.st >= lp) c++, lp = x.en + 1;

        if(c > prin) prin = c, popo = p;
    }

    cout << prin << endl;
    int lp = 0;
    for(auto x : mat[popo])
    {
        if(x.st >= lp) lp = x.en + 1, cout << x.st + 1 << ' ' << x.en + 1 << endl;
    }
    return 0;
}
