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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

struct info
{
    int l,mc,tc,v;
}dfa[300010];

vector<int>mat[300010];
void dfs(int p)
{
    int a=0,x;
    dfa[p].v=1; dfa[p].tc=1; dfa[p].mc=p;
    FOR(i,0,(int)mat[p].size()-1)
    {
        x=mat[p][i];
        if(dfa[x].v==0)
        {
            dfs(x);
            dfa[p].tc+=dfa[x].tc;
            if(a<dfa[x].tc) a=dfa[x].tc, dfa[p].mc=x;
        }
    }
}

int cen(int p,int tn)
{
    //cout<<p<<' '<<tn<<NL;
    int x,y,z,a,b,c;
    y=dfa[p].mc;
    x=max(tn-dfa[p].tc,dfa[y].tc);

    if(x*2<=tn||p==y) return p;
    else return dfa[p].mc=cen(dfa[p].mc,tn);
}
int ans[300010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    //int tc;
    //cin>>tc;
    //FOR(tt,1,tc)
    //{
      //  cout<<"Case "<<tt<<": "<<NL;
        mem(dfa,0);
        FOR(i,1,300001) mat[i].clear();
        int i, j, x, y, n, m,a;
        cin>>n>>m;
        FOR(i,2,n)
        {
            cin>>x;
            mat[i].PB(x); mat[x].PB(i);
        }
        dfs(1);
        FOR(i,1,n)ans[i]=cen(i,dfa[i].tc);
        FOR(i,1,m)
        {
            cin>>a;
            cout<<ans[a]<<NL;
        }
    //}
    return 0;
}
