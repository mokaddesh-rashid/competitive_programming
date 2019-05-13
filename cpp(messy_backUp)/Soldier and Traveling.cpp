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
#define MAX 210
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int mat[MAX][MAX], lev[MAX], flow[MAX], n, pa[MAX], des, ans[MAX][MAX], m, np;
queue<int>que;

int ar[MAX],br[MAX],chi[MAX],cha[MAX];

void bfs_lev(int p)
{
    mem(lev,0);
    que.push(p);
    lev[p]=1;

    while(!que.empty())
    {
        p=que.front(); que.pop();
        FOR(i,0,n+1)
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
        FOR(i,0,n+1)
        {
            if(mat[p][i]>0&&lev[i]==lev[p]+1&&flow[i]==0)
            {
                pa[i]=p;
                flow[i]=min(flow[p],mat[p][i]);
                que.push(i);
            }
        }
    }
    ////cout<<des<<' '<<flow[des]<<NL;
    int cnt=0;
    p=des;
    while(pa[p]!=-1)
    {
        int pp=pa[p];
        mat[pp][p]-=flow[des];
        mat[p][pp]+=flow[des];

        ans[pp][p]+=flow[des];
        cnt++;
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
    int i,j,a,b,c,d=0,e=0;

    cin>>n>>m; des=n+1;
    FOR(i,1,n)
    {
        cin>>c; chi[i]=c;
        mat[0][i]+=c;
        d+=c;
    }
    FOR(i,1,n)
    {
        cin>>c; cha[i]=c;
        mat[i][des]+=c;
        e+=c;
    }

    FOR(i,1,m)
    {
        cin>>a>>b;
        mat[a][b]+=mod;
        mat[b][a]+=mod;
    }

    a=MAX_flow(0);
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            int v=ans[i][j];
            chi[i]-=v;
            chi[j]+=v;
            ///cout<<i<<' '<<j<<' '<<v<<NL;
        }
    }

    if(a==d&&a==e)
    {
        cout<<"YES"<<NL;
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(i==j)
                {
                    cout<<chi[i]<<' ';
                    if(max(0,chi[i]-ar[i])<=9)cout<<' ';
                }
                else
                {
                    cout<<ans[i][j]<<' ';
                    if(ans[i][j]<=9)cout<<' ';
                }

            }
            cout<<NL;
        }
    }
    else cout<<"NO"<<NL;

    return 0;
}




