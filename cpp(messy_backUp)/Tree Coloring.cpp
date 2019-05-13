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

int n,k,op[MAX],lev[MAX];
vector<int>mat[MAX];

int dfs(int p,int pa)
{
    int  v=(int)mat[p].size()-1, pv=k;
    if(p!=pa)v--;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            lev[x]=lev[p]+1;
            op[x]=pv-v;v--;
            dfs(x,p);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y;
    LL c=1;

    cin>>n>>k;
    FOR(i,0,n-2)
    {
        cin>>x>>y;
        mat[x].PB(y);
        mat[y].PB(x);
    }
    op[1]=k;
    dfs(1,1);
    FOR(i,1,n)
    {
        //cout<<op[i]<<NL;
        op[i]-=(min(2,lev[i]));
        //cout<<op[i]<<NL;
        c*=op[i];
    }

    c=max((LL)0,c);

    cout<<c<<NL;
    return 0;
}


