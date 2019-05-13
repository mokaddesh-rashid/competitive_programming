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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int on[MAX],ze[MAX],n,val[MAX],cnt,paa[MAX],ans[MAX],co;
vector<int>mat[MAX];

void dfs(int p,int pa)
{
    if(val[p]==0) on[p]=1,ze[p]=-1;
    else on[p]=-1,ze[p]=1;

    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            paa[x]=p;
            dfs(x,p);
            if(on[x]>0)on[p]+=on[x];
            if(ze[x]>0)ze[p]+=ze[x];
        }
    }
    cnt=max(cnt,on[p]);
    cnt=max(cnt,ze[p]);

    return;
}

void prin(int p,int ty)
{
    ans[co++]=p;
    if(ty==1)
    {
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(x!=paa[p]&&on[x]>0) prin(x,ty);
        }
    }
    else
    {
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(x!=paa[p]&&ze[x]>0) prin(x,ty);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,n,m,a,b,c=0;

    cin>>n;
    FOR(i,1,n)cin>>val[i];
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b);mat[b].PB(a);
    }
    dfs(1,1);
    FOR(i,1,n)
    {
        if(on[i]==cnt&&c==0)
        {
            prin(i,1);
            c=1;
        }
        if(ze[i]==cnt&&c==0)
        {
            prin(i,2);
            c=1;
        }
    }
    cout<<cnt<<NL<<co<<NL;
    sort(ans,ans+co);
    FOR(i,0,co-1)cout<<ans[i]<<' ';
    return 0;
}



