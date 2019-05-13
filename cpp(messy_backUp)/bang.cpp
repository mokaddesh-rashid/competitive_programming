#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define LL          unsigned long long
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
typedef pair<int,int> PR;
typedef pair<LL,PR> node;

int pa[MAX];

void initDsu(int n){FOR(i,0,n) pa[i] = i;}
int finPa(int p){return pa[p] == p ? p : pa[p] = finPa( pa[p] );}
int mergeNode(int u,int v)
{
    int r1 = finPa( u ), r2 = finPa( v );

    if(r1 == r2) return 0;
    pa[r1] = r2;
    return 1;
}

vector<node> poi;
map<PR,bool> mopa;

int main()
{
    ios::sync_with_stdio(false);

    int n, m, c = -1, u, v, p;
    LL prin = 0;

    cin >> n >> m; initDsu( n );
    FOR(i,1,n)
    {
        cin >> v;
        if(c == -1) c = v, p = i;
        else if(c > v) c = v, p = i;
    }
    FOR(i,0,m-1)
    {
        cin >> u >> v >> c; mopa[MP(u, v)] = 1;
        poi.PB( MP(c, MP(u, v)) );
    }
    FOR(i,1,n)
    {
        u = p; v = i;
        if(mopa[MP(u, v)]) continue;
        poi.PB( MP(c, MP(u, v)) );
    }
    sort(poi.begin(), poi.end());

    for(auto x : poi)
    {
        u = x.S.F; v = x.S.S; c = x.F;
        cout << u << ' ' << v << ' ' << c << endl;
        prin += (mergeNode(u, v) * c);
    }

    cout << prin << endl;

    return 0;
}
