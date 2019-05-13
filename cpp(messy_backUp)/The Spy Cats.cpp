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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, pa, st, en, l, c, is_art, cn;
}dfa[100010];

vector<int> mat[100010];
int ti, cnt, pp;

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        dfa[p].st = ti, ti++;
        dfa[p].l = dfa[p].st;

        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                if( p == 1 ) pp++;
                dfa[x].pa = p;
                dfs(x);
                if( dfa[x].l >= dfa[p].st ) dfa[p].is_art = 1; /// for this node is it articulation or not
                dfa[p].l = min( dfa[p].l, dfa[x].l );
            }
            else if( dfa[p].pa != x )
                dfa[p].l = min( dfa[p].l, dfa[x].st );

            dfa[p].cn+=dfa[x].cn;
        }
        dfa[p].cn++;
        cnt += dfa[p].is_art;


    }
}


vector<int>ase;
int vis[sz], cnt;

void s_dfs(int p)
{
    cnt++;
    ase.PB(p);
    vis[p]=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(vis[x]==0) dfs(x);
    }
    return;
}

LL sa[sz], co[sz];
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;
    while( t-- )
    {
        memset(dfa,0,sizeof(dfa));
        ti = 1;
        pp = cnt = 0;
        LL i, j, x, y, n, m, a, b, c;

        cin>>n>>m;
        for(i=0;i<=n+1;i++) mat[i].clear( );

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;
            mat[x].push_back( y );
            mat[y].push_back( x );
        }
        dfs(1);

        mem(vis,0);
        FOR(i,1,n)
        {
            if(vis[i]==0)
            {
                s_dfs(i);
                a=ase[i].size();
                b=(a*(a-1))/2;
                FOR(j,0,(int)ase.size()-1)
                {
                    x=ase[j];
                    co[x]=a
                    sa[x]=b;
                }
                ase.clear();
            }
        }


        FOR(i,1,n)
        {
            if(dfa[i].is_art==1)
            {
                mem(cnt,0);
                FOR(j,1,(int)mat[i].size-1)
                {
                    x=mat[i][j];
                    c=cnt*(cnt-1); c/=2;
                    cout<<sa[i]-c<<NL;
                }
            }
            else cout<<co[i]<<' '<<NL;
        }

    }
    return 0;

}
