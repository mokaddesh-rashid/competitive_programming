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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector <int> mat[sz], cost[sz];
struct info
{
    int l, lf, ri;
}lar[sz]; // array of info about input

int dfa[sz], n, sp_t[sz][20], pol, ms, co;
pr val[sz];

int dfs(int p)
{
    dfa[pol]=p; lar[p].lf=pol; pol++;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i], y=cost[p][i];
        if(lar[x].lf==0)
        {
            sp_t[x][0]=p;

            lar[x].l=lar[p].l+1;
            val[co].F=y; val[co].S=x; co++;

            dfs(x);
        }
    }
    dfa[pol]=p; lar[p].ri=pol; pol++;

}

void cre_t()
{
    for(int i=1; i<ms; i++ )
    {
        for(int j=1; j<=n; j++ )
        {
            int x = sp_t[j][i-1], y;
            if( x != -1 ) sp_t[j][i] = sp_t[x][i-1];
            else sp_t[j][i] = -1;
        }
    }
}

int fi_lca( int x, int y, int jm )
{
    if( sp_t[x][jm] == sp_t[y][jm] )
   {
       if( x == y ) return x;
       else if( jm == 0 ) return sp_t[x][jm];
       else return fi_lca( x, y, jm-1 );
   }
   else
   {
       x = sp_t[x][jm]; y = sp_t[y][jm];
       return fi_lca( x, y, jm );
   }
}

int mak_sm( int x, int y, int jm )/// make x`s and y`s level same and x have larger level
{
   int z = sp_t[x][jm];

   if( lar[x].l == lar[y].l ) return x;
   else if( z==-1 ||  lar[z].l < lar[y].l ) return mak_sm( x, y, jm-1 );
   else return mak_sm( z, y, jm );
}


struct Node
{
    int sum;
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum=v;
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return (lft^rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)>>1, st, en, v);
    update(rnd, ((b+e)>>1)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum^tree[rnd].sum;
}



pr ar[sz], in[sz];
int ans[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(lar,0); mem(sp_t,-1); mem(tree,0);
        int i,j,m,a,b,c,x,y,z,pa;

        cin>>n;
        clean(mat,n); clean(cost,n);
        FOR(i,1,n-1)
        {
            cin>>a>>b>>c;
            mat[a].PB(b); mat[b].PB(a);
            cost[a].PB(c); cost[b].PB(c);
        }
        pol=1; lar[1].l=1; ms=19; co=0;
        dfs(1); cre_t();

        sort(val,val+co);

        cin>>m;
        FOR(i,0,m-1)
        {
            cin>>in[i].F>>in[i].S;
            cin>>ar[i].F; ar[i].S=i;
        }
        sort(ar,ar+m);

        c=0;
        FOR(i,0,m-1)
        {
            while(c<co&&ar[i].F>=val[c].F)
            {
                x=val[c].S;
                a=lar[x].lf; b=lar[x].ri;

                update(1,1,sz,a,a,val[c].F);
                update(1,1,sz,b,b,val[c].F);
                c++;
            }

            x=ar[i].S;
            a=in[x].F; b=in[x].S;

            if(lar[a].l>lar[b].l) a=mak_sm(a,b,ms);
            else if(lar[a].l<lar[b].l) b=mak_sm(b,a,ms);

            pa=fi_lca(a,b,ms);

            a=in[x].F; b=in[x].S;
            x=query(1,1,sz,lar[pa].lf+1,lar[a].lf);
            y=query(1,1,sz,lar[pa].lf+1,lar[b].lf);

            ans[ar[i].S]=x^y;
        }

        FOR(i,0,m-1) cout<<ans[i]<<NL;
    }

    return 0;
}



