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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int mat[MAX][MAX], lev[MAX], flow[MAX], n, pa[MAX], des, ans[MAX][MAX], m, np;
queue<int>que;

void bfs_lev(int p)
{
    mem(lev,0);
    que.push(p);
    lev[p]=1;

    while(!que.empty())
    {
        p=que.front(); que.pop();
        FOR(i,0,n)
        {
            if(mat[p][i]>0&&lev[i]==0)
            {
                lev[i]=lev[p]+1;
                que.push(i);
            }
        }
    }
}

int bfs_flow(int p)
{
    mem(flow,0); mem(pa,-1);
    que.push(p);
    flow[p]=mod;///max value

    while(!que.empty())
    {
        p=que.front(); que.pop();
        FOR(i,0,n)
        {
            if(mat[p][i]>0&&lev[i]==lev[p]+1&&flow[i]==0)
            {
                pa[i]=p;
                flow[i]=min(flow[p],mat[p][i]);
                que.push(i);
            }
        }
    }

    p=des;
    while(pa[p]!=-1)
    {
        int pp=pa[p];
        mat[pp][p]-=flow[des];
        mat[p][pp]+=flow[des];

        int a=p, b=pp;

        if(a>np) ans[b][a-np]+=flow[des];
        else ans[a][b-np]+=flow[des];

        p=pp;
    }

    return flow[des];
}

int MAX_flow(int p)
{
    int ret=0;
    while(true)
    {
        int x=bfs_flow(p);

        if(x==0)
        {
            bfs_lev(p);
            x=bfs_flow(p);

            if(x==0) return ret;
            else ret+=x;
        }
        else ret+=x;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    mem(mat,0);
    int i,j,a,b,c;

    cin>>n>>m; des=n+m+1;
    FOR(i,1,n)
    {
        cin>>c;
       /// cout<<0<<' '<<i<<NL;
        mat[0][i]+=c;
    }
    FOR(i,1,m)
    {
        cin>>c;
        mat[i+n][des]+=c;
       /// cout<<i+n<<' '<<des<<NL;
    }

    FOR(i,1,n)
        FOR(j,1,m)
            mat[i][n+j]=mod;///max value
    np=n;
    n=n+m+1;
    cout<<MAX_flow(0)<<NL;
    FOR(i,1,3)
    {
        FOR(j,1,3)cout<<ans[i][j]<<' ';
        cout<<NL;
    }

    return 0;
}



