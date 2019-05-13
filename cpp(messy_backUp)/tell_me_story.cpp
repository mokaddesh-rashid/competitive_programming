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

int cost[MAX], col[MAX], val[MAX], go[MAX], can[MAX];
vector<int> mat[MAX];
int lev[MAX], low[MAX], ins[MAX], ti, cCol, newVal[MAX];
stack<int> stk;

void tarzan(int p)
{
    lev[p] = low[p] = ++ti;
    ins[p] = 1; stk.push( p );

    for(auto x : mat[p])
    {
        if(!lev[x]) {tarzan( x ); low[p] = min(low[p], low[x]);}
        else if(ins[x]) low[p] = min(low[p], lev[x]);
    }

    if(low[p] == lev[p])
    {
        cCol++;
        int V = val[p];

        while(true)
        {
            int cp = stk.top(); stk.pop();

            ins[cp] = 0; col[cp] = cCol;
            V = min(val[cp], V);
//            cout << cp << ' ';

            if(cp == p) break;
        }
//        cout << endl << "Current colo " << cCol << ' ' << " Value " << V << endl;
        newVal[cCol] = V;
    }
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    int n;

    cin >> n;
    FOR(i,1,n) cin >> val[i];
    FOR(i,1,n) cin >> go[i], mat[i].PB( go[i] );

    FOR(i,1,n) if(!lev[i]) tarzan( i );
    FOR(i,1,n) mat[i].clear();

    FOR(i,1,n)
    {
        int u = col[ i ], v = col[ go[i] ];
        if(u == v) continue;
        ins[u]++;
    }

    int prin = 0;

    FOR(i,1,cCol)
    {
        if(ins[i]) continue;
        prin += newVal[i];
    }

    cout << prin << endl;

    return 0;
}

