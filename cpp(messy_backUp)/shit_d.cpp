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
    lar[p].lf=1;
    cout<<p<<NL;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i], y=cost[p][i];
        if(lar[x].lf==0)
        {
            sp_t[x][0]=p;

            lar[x].l=lar[p].l+1;

            //dfs(x);
        }
    }

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


int solve(int a,int b,int c)
{
    int x,y,z,pa,lx,ly,lpa;

    x=a; y=b;
    if(lar[x].l>lar[y].l) x=mak_sm(x,y,ms);
    else if(lar[x].l<lar[y].l) b=mak_sm(y,x,ms);

    pa=fi_lca(x,y,ms);

    x=pa; y=c;
    if(lar[x].l>lar[y].l) x=mak_sm(x,y,ms);
    else if(lar[x].l<lar[y].l) b=mak_sm(y,x,ms);

    lpa=fi_lca(x,y,ms);

    int temp=0;
    temp=max(temp,abs(lar[a].l-lar[lpa].l));
    temp=max(temp,abs(lar[b].l-lar[lpa].l));
    temp=max(temp,abs(lar[c].l-lar[lpa].l));

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);

    mem(lar,0); mem(sp_t,-1);
    int i,j,m,a,b,c,x,y,z,pa,q;

    cin>>n>>q;

    FOR(i,2,n)
    {
        cin>>a; b=i;
        mat[a].PB(b); mat[b].PB(a);
    }
    pol=1; lar[1].l=1; ms=19; co=0;
    dfs(1); ///cre_t();

    FOR(i,1,q)
    {
        //cin>>x>>y>>z;
        ///cout<<solve(x,y,z)<<NL;
    }

    return 0;
}




