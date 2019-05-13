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
#define MAX 23
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int pa[MAX], col[MAX];
void initDsu(){FOR(i,0,MAX-1) pa[i] = i, col[i] = 0;}
int finPa(int p){return pa[p] == p ? p : pa[p] = finPa( pa[p] );}
int getCol(int p){return pa[p] == p ? col[p] : col[p] = col[p] ^ getCol( pa[p] );}

int mergeNode(int u,int v)
{
    int cU = getCol( u ), cV = getCol( v );
    int r1 = finPa( u ), r2 = finPa( v );

    if(r1 == r2) return (cU == cV);

    pa[r1] = r2;
    col[r1] = (cU == cV);
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int u, v;

    initDsu();
    for(;;)
    {
        cin >> u >> v;
        cout << mergeNode(u, v) << endl;
    }

    return 0;
}

