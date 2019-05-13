#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define sfff(a,b,c)    scanf("%I64d %I64d %I64d", &a, &b, &c)
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
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL dude[MAX],stop[MAX];

void info()
{
    FOR(i,1,20010)
    {
        LL x=(i*(i+1))/2;
        stop[i]=x;
        dude[i]=dude[i-1]+x;
    }
}

LL fin_pos(LL v)
{
    LL ret=upper_bound(stop,stop+20011,v)-stop;
    ret--;
    return ret;
}

LL  ret_val(LL v)
{
    LL x,y,z,ret=0;

    x=fin_pos(v); y=dude[x];
    z=v*x;
   //// cout<<v<<' '<<z<<' '<<y<<' '<<(z-y)+v<<' '<<stop[x]<<' '<<x<<NL;
    return (z-y)+v;

}

vector<LL>mat[MAX],cost[MAX];
LL lev[MAX],low[MAX],tim,col,color[MAX],Cval[MAX],value[MAX],in[MAX];
stack<LL>stk;

void dfs(LL p)
{
    LL x,y;

    stk.push(p); in[p]=1;
    low[p]=lev[p]=++tim;

    FOR(i,0,(LL)mat[p].size()-1)
    {
        x=mat[p][i]; y=cost[p][i];
        if(lev[x]==0)
        {
            dfs(x);
            low[p]=min(low[p],low[x]);
        }
        else if(in[x]==1) low[p]=min(low[p],lev[x]);
    }

    if(low[p]==lev[p])
    {
        LL cnt=0;
        col++;
        while(!stk.empty())
        {
            x=stk.top(); stk.pop(); cnt++;
            color[x]=col;
            in[x]=0;
            if(x==p)break;
        }
    }
}


vector<LL>Dmat[MAX],Dcost[MAX];
LL dp[MAX];

LL rec(LL p)
{
    if(Dmat[p].size()==0)return Cval[p];
    if(dp[p]!=-1)return dp[p];

    LL temp=0;

    FOR(i,0,(LL)Dmat[p].size()-1)
    {
        temp=max(temp,rec(Dmat[p][i])+Dcost[p][i]);
    }

    return dp[p]=temp+Cval[p];
}

void up(LL n)
{
    FOR(i,1,n)
    {
        LL a=color[i];
        Cval[a]+=value[i];
    }

    LL a,b,c,d;

    FOR(i,1,n)
    {
        a=color[i];

        FOR(j,0,(LL)mat[i].size()-1)
        {
          b=color[mat[i][j]]; c=cost[i][j];

          if(a!=b) Dmat[a].PB(b), Dcost[a].PB(c);
          else Cval[a]+=ret_val(c);

        }
    }
}


int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    info();
    LL i,j,n,m,a,b,c,s;


    sff(n,m);///cin>>n>>m;
    FOR(i,1,m)
    {
       sfff(a,b,c);////cin>>a>>b>>c;

       if(a==b)
       {
           value[a]+=ret_val(c);
           continue;
       }
       mat[a].PB(b);
       cost[a].PB(c);
    }
    sf(s);///cin>>s;
    dfs(s);

    up(n);
    s=color[s];
    pf("%I64d\n",rec(s));///cout<<rec(s)<<NL;

    return 0;
}

