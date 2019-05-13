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
typedef pair<int,int> pr;

vector<int>col[MAX], tim[MAX];
int ar[MAX];
map<pr,pr> mopa;

pr finPa(int p,int lev)
{
   if( mopa[MP(p, lev)] != MP(0, 0)) return mopa[MP(p, lev)] = finPa(mopa[MP(p, lev)].F, mopa[MP(p, lev)].S);

   int x = upper_bound(tim[p].begin(), tim[p].end(), lev) - tim[p].begin();
   if(x == tim[p].size()) return MP(p, lev);
   return mopa[MP(p, lev)] = finPa(col[p][x], tim[p][x]);
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    int x, y, n, m, ty;
    cin >> n >> m;

    FOR(i,0,n-1) cin >> ar[i];

    FOR(i,0,m-1)
    {
        cin >> ty;
        if(ty == 1)
        {
            cin >> x >> y;
            col[x].PB( y );
            tim[x].PB( i + 1 );
        }
        else
        {
            cin >> x; x--;
            cout << finPa( ar[x], 0).F << endl;
        }
    }

    return 0;
}

