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
typedef pair<int,int> pr;

struct node
{
    LL v, pa, c;
}dfa[100010];
vector<int> mat[100010];
int ck, col[100010], cc;
void dfs(int p ,int c)
{
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            if(col[x]!=c) ck=1;
            dfs(x,c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, a, b;
    a=b=-1;
    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>x>>y;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }
    FOR(i,1,n) cin>>col[i];

    FOR(i,1,n)
    {
        int sz=mat[i].size()-1;
        FOR(j,0,sz)
        {
            x=mat[i][j];
            if(col[x]!=col[i]) a=i, b=x;
        }
    }
    //cout<<a<<' '<<b<<endl;
    if(a==-1) cout<<"YES\n1"<<endl;
    else
    {
        mem(dfa,0);
        ck=0;
        dfa[a].v=1;
        int sz=mat[a].size()-1;
        FOR(i,0,sz)
        {
            x=mat[a][i];
            dfs(x,col[x]);
        }
        if(ck==0)
        {
            cout<<"YES"<<endl;
            cout<<a<<endl;
            return 0;
        }
        mem(dfa,0);
        ck=0;
        dfa[b].v=1;
        sz=mat[b].size()-1;
        FOR(i,0,sz)
        {
            x=mat[b][i];
            dfs(x,col[x]);
        }
        if(ck==0)
        {
            cout<<"YES"<<endl;
            cout<<b<<endl;
            return 0;
        }
        cout<<"NO"<<endl;
    }

    return 0;

}




