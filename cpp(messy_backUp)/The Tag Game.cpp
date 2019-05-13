#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define FF first
#define SS second
#define sz 200010
typedef pair<int,int> pr;

struct node
{
    LL v, pa, l;
}dfa[sz];
vector<int> mat[sz];


void dfs( int p )
{
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            dfa[x].l = dfa[p].l+1;
            dfa[x].pa = p;
            dfs(x);
        }
    }
}


int dis[sz];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, a, b, c=0;

    cin>>n>>m;
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }
    dfs(1);
    FOR(i,1,n) dis[i]=dfa[i].l;

    mem(dfa,0);
    dfs(m);

    FOR(i,1,n)
    {
        ///cout<<i<<' '<<dfa[i].l<<' '<<dis[i]<<NL;
        if(dfa[i].l<dis[i])
        {
           a=dis[i]*2;
           c=max(a,c);
        }
    }

    cout<<c<<NL;

    return 0;

}



