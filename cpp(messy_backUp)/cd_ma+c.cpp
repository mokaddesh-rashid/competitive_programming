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

int child[MAX],sib[MAX],n,k,m;
vector<int>mat[MAX];

int dfs(int p,int pa)
{
    int pc;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            if(child[p]==-1) child[p]=x,pc=x;
            else sib[pc]=x, pc=x;
            dfs(x,p);
        }
    }
}

int rec(int p,int x,int v,int t)
{
    cout<<p<<' '<<v<<NL;
    if(p==-1&&v>0)return 0;
    if(p==-1)return 1;


    int temp=k-1,lola=0;
    FOR(i,1,x)
    {
        temp*=rec(child[p],x-i,i,0);
        //cout<<child[p]<<' '<<" l "<<p<<NL;
    }

    temp += rec(child[p],x-1,0,1);
    temp += (m-k)*(child[p],x,0,2);

    if(t==0)
    {
        lola=(m-1)*rec(sib[p],x,v,t);
        if(v>0) lola+=rec(sib[p],x,v-1,t);
    }
    else if(t==1) lola=(k-1)*rec(sib[p],x,v,t);
    else if(t==2) lola=(m-1)*rec(sib[p],x,v,t);

    return temp+lola;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(child,-1); mem(sib,-1);
    int i,j,a,b,x;

    cin>>n>>m;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    dfs(1,1);

    cin>>k>>x;
    cout<<rec(1,x,0,0)<<NL;

    return 0;
}


