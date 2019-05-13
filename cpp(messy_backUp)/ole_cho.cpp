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
#define cnd tree[lev][idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 400010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct Node{
    int lazy, val;
};

Node tree[2][4*MAX];
int arr[2][MAX];

void init(int lev,int idx, int b, int e )
{
    if(b==e)
    {
        cnd.val = arr[lev][b];
        return ;
    }
    init(lev, lnd, b, (b+e)>>1);
    init(lev, rnd, ((b+e)>>1)+1, e);
    cnd.val=tree[lev][lnd].val+tree[lev][rnd].val;
}

void update_node(int lev,int idx, int b, int e, int v)
{
    cnd.val += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int lev,int idx, int b, int e)
{
    if(cnd.lazy!=0)
    {
        update_node(lev, lnd, b, (b+e)>>1, cnd.lazy);
        update_node(lev, rnd, ((b+e)>>1)+1, e, cnd.lazy);
        cnd.lazy = 0;
    }
}


int query(int lev, int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

    lazy_update(lev, idx, b, e);
    int lft = query(lev, lnd, b, (b+e)>>1, st, en);
    int rgt = query(lev, rnd, ((b+e)>>1)+1, e, st, en);
    return lft+rgt;
}

void update(int lev,int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(lev, idx, b, e, v);
        return ;
    }

    lazy_update(lev, idx, b, e);
    update(lev, lnd, b, (b+e)>>1, st, en, v);
    update(lev, rnd, ((b+e)>>1)+1, e, st, en, v);
    cnd.val = tree[lev][lnd].val+tree[lev][rnd].val;
}

int dfa[MAX], lf[MAX], rg[MAX], ti, lev[MAX];
vector<int>mat[MAX];

void dfs(int p,int pa)
{
    lf[p]=ti; dfa[ti]=p;
    ti++;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            lev[x]=lev[p]+1;
            dfs(x,p);
        }
    }
    rg[p]=ti; dfa[ti]=p;
    ti++;
}

int ar[MAX];
int main()
{
    int i,j,n,m,a,b,c=0,d,x,q;

    sff(n,q);
    FOR(i,1,n) sf(ar[i]);
    FOR(i,1,n-1)
    {
        sff(a,b);
        mat[a].PB(b); mat[b].PB(a);
    }
    ti=1; lev[1]=0;
    dfs(1,1);

    FOR(i,1,n)
    {
        x=lev[i]%2;
        update(x,1,1,MAX,lf[i],lf[i],ar[i]);
    }

    FOR(i,1,q)
    {
        sff(a,b);
        if(a==1)
        {
            sf(c);
            x=lev[b]%2;
            update(x,1,1,MAX,lf[b],rg[b],c);
            x=(x+1)%2;
            update(x,1,1,MAX,lf[b]+1,rg[b],c*-1);
        }
        else
        {
            x=lev[b]%2;
            c=query(x,1,1,MAX,lf[b],lf[b]);
            x=(x+1)%2;
            c+=query(x,1,1,MAX,lf[b]+1,lf[b]);
            pf("%d\n",c);
        }
    }

    return 0;
}

