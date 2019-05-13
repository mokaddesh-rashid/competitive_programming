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
#define sesh first
#define shuru second
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pii;

int pa[MAX], tok[MAX];
void init() {FOR(i,0,MAX-1) pa[i] = i, tok[i] = 1;}
int finPa(int p) {return pa[p] == p ? p : pa[p] = finPa( pa[p] );}
void mergeNode(int u,int v)
{
    int r1 = finPa( u ), r2 = finPa( v );

    if(r1 == r2) return;
    pa[r1] = r2;
    return;
}

int n, q;
pii ara[MAX];

int getVal(int l,int r)
{
    int ret = 0;

    while(l <= r)
    {
        ret += tok[l]; tok[l] = 0;
        l++;
//        mergeNode(l, l + 1);
//        l = finPa( l );
    }

    return ret;
}

int main()
{
    int tc;

    sf(tc);
    FOR(tt,1,tc)
    {
        init();

        sff(n, q);
        FOR(i,0,q-1) sff(ara[i].shuru, ara[i].sesh);
        sort(ara, ara + q);

        int prin = 0;

        FOR(i,0,q-1)
        {
            int l = ara[i].shuru, r = ara[i].sesh;

            if(!i) prin = getVal(l, r);
            else prin = min(prin, getVal(l, r));
        }

        pf("Case #%d: %d\n", tt, prin);
    }
    return 0;
}

