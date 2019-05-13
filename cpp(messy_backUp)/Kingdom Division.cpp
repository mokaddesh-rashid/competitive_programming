#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
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
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

LL dp[100010][3][3], out[1000], root, vis[100010], shim, lev[100010], ml;
vector<int>mat[100010], sec[100010];

void dfs(int p, int l )
{
    ml=max(ml,(LL)l);
    vis[p]=1;
    lev[p]=l;
    int sz=(int)sec[p].size()-1;
    FOR(i,0,sz)
    {
        int x=sec[p][i];
        if(vis[x]==0)
        {
            //cout<<p<<' '<<x<<endl;
            out[p]++;
            mat[p].PB(x);
            dfs(x,l+1);
        }
    }
}

LL rec(int p, int v, int z)
{
    //cout<<p<<' '<<v<<endl;
    //if(mat[p].size()==0&&p==shim) return 1;
    if(mat[p].size()==0) return dp[p][v][z]=z;
    if(dp[p][v][z]!=-1) return dp[p][v][z];

    int sz=mat[p].size();
    sz--;
    LL temp=0, c=0, tp, re=0, a, b;
    FOR(i,0,sz)
    {
        int x=mat[p][i];
        if((p==root||v==0||(mat[x].size()==0))&&c==0) temp+=rec(x,1,1), c=1;
        else if(p==root||v==0||(mat[x].size()==0)) temp+=rec(x,1,0);
        else
        {
            if(c==0)
            {
                c=1;
                temp+=(rec(x,1,1)+rec(x,0,1));
            }
            else temp+=(rec(x,1,0)+rec(x,0,1));
        }
        temp%=mod;
    }
    c=0;
    FOR(i,0,sz)
    {
        int x=mat[p][i];
        if((p==root||v==0||(mat[x].size()==0))&&c==0) tp=rec(x,1,1), c=1;
        else if(p==root||v==0||(mat[x].size()==0)) tp=rec(x,1,0);
        else
        {
            if(c==0)
            {
                c=1;
                tp=(rec(x,1,1)+rec(x,0,1));
            }
            else tp=(rec(x,1,0)+rec(x,0,1));
        }
        a=temp-tp;
        a=a*tp;
        re+=a;
        re%=mod;
    }
    if(re==0) re=temp;
    return dp[p][v][z]=(re%mod);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    LL i, j, x, y, n, m, c=0;
    cin >>n;
    FOR(i,1,n-1)
    {
        cin>>x>>y;
        sec[x].PB(y);
        sec[y].PB(x);
    }
    FOR(i,1,n)
    {
        x=sec[i].size();
        if(x==1) root=i;
    }
    dfs(root,0);
    //cout<<root<<' '<<c<<' '<<shim<<endl;
    x=rec(root,0,1);
    x=x*2;
    cout<<x;
    return 0;
}
