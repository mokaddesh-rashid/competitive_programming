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
#define MAX 2010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int pa[MAX], bita[MAX], val[MAX];

void initDsu()
{
   FOR(i,1,MAX-1) pa[i] = i;
}

int finPa(int p)
{
    return pa[p] == p ? p : pa[p] = finPa( pa[p]);
}

pair<int,PR> ara[MAX];

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int n, m, q, u, v;

    cin >> n >> m >> q;
    FOR(i,1,n) val[i] = 1;

    int prin = 0;
    initDsu();

    FOR(i,0,q-1)
    {
        cin >> u >> v; v += n;
        int r1 = finPa( u ), r2 = finPa( v );

        if( !(bita[r1] && bita[r2]) )
        {
           prin += val[r1]; val[r1] = 0;

           if(r1 != r2) bita[r1] |= bita[r2];
           else bita[r1] = 1;

           pa[r2] = r1;
        }

        cout << prin << endl;
    }


    return 0;
}
