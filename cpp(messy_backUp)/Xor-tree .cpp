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
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, p, c, val, ty;
}dfa[sz];
vector<int> mat[sz], ans;

void dfs( int p )
{
    if(dfa[p].p%2) dfa[p].val++;
    dfa[p].val%=2;
    ///cout<<p<<' '<<dfa[p].p<<' '<<dfa[p].c<<NL;
    if(dfa[p].val!=dfa[p].ty) dfa[p].p++, ans.PB(p);

    dfa[p].v=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x = mat[p][i];
        if(dfa[x].v==0)
        {
            dfa[x].p+=dfa[p].c; dfa[x].c+=dfa[p].p;
            dfs(x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m;

    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>x>>y;
        mat[x].PB(y);
        mat[y].PB(x);
    }

    FOR(i,1,n) cin>>dfa[i].val;
    FOR(i,1,n) cin>>dfa[i].ty;

    dfs(1);
    cout<<(int)ans.size()<<NL;
    FOR(i,0,(int)ans.size()-1) cout<<ans[i]<<NL;
    return 0;

}




