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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

vector<PR> mat[MAX];
vector<int> pola[MAX];
int n, k, dis[MAX];

int dfs(int p,int pa)
{
    dis[p] = 0; pola[p].clear();
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;

        dfs(x.F, p);

        pola[p].PB( dis[x.F] + x.S );
        dis[p] = max(dis[p], dis[x.F] + x.S);
    }
    sort(pola[p].begin(), pola[p].end());
    reverse(pola[p].begin(), pola[p].end());

}

void rec(int p,int pa,int val)
{
    dis[p] = max(dis[p], val);
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;

        int newVal = pola[p][0];
        if(newVal == dis[x.F] + x.S)
        {
            newVal = 0;
            if(pola[p].size() > 1) newVal = pola[p][1];
        }
        rec(x.F, p, max(val, newVal) + x.S);
    }
    return;
}

void input()
{
    int a, b, c;

    cin >> n >> k;
    FOR(i,1,n-1)
    {
        cin >> a >> b >> c;
        mat[a].PB( MP(b, c) );
        mat[b].PB( MP(a, c) );
    }
    return;
}

vector<int> Root;
void startNode()
{
    dfs(1, 1);
    rec(1, 1, 0);

    int p = 1;
    FOR(i,1,n)
    {
        if(dis[p] > dis[i]) p = i, Root.clear();
        if(dis[p] == dis[i]) Root.push_back( i );

    }
    return;
}
///********************

int lev[MAX];
int go(int p,int pa)
{

}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int prin = -1;

    input();
    startNode();

    for(auto x : Root)
    {

    }

    cout << prin << endl;

    return 0;
}
