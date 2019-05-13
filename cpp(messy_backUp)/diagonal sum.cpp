#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k)  for(int i=j;i<=k;i++)
#define NL endl
#define MAX 210
#define MP make_pair
#define LL  long long
#define PR pair<int,int>
#define F first
#define S second

int mat[MAX][MAX], lev[MAX], flow[MAX], n, pa[MAX], des;
queue<int>que;

void bfs_lev(int p)
{
    mem(lev,0);
    que.push(p);
    lev[p]=1;

    while(!que.empty())
    {
        p=que.front(); que.pop();
        FOR(i,0,des)
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
    flow[p]=1000000007;///max value

    while(!que.empty())
    {
    ///cout<<p<<NL;
        p=que.front(); que.pop();
        FOR(i,0,des)
        {
            ////cout<<i<<' '<<mat[p][i]<<' '<<lev[i]<<NL;
            if(mat[p][i]>0&&lev[i]==lev[p]+1&&flow[i]==0)
            {
                ////cout<<p<<"push"<<i<<NL;
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


int cnt, ar[MAX][MAX], m, thaka[MAX][MAX], ans[MAX][MAX];
map<PR,PR> mopa;

void up(int x,int y,int v)
{

    ////cout<<x<<' '<<y<<' '<<v<<NL;
    if(x <= 0 || y <= 0 || x > n || y > m) return;
    cnt++;
    ar[x][y] = v;
    up(x-1,y+1,v);

    return;
}

void Dup(int x,int y,int v)
{
    if(x <= 0 || y <= 0 || x > n || y > m) return;
    cnt++;
    int a, b, c;
    a = ar[x][y];
    mat[a][v] = 99;
    ////mat[v][a] = 100;
   /// cout<<a<<' '<<v<<' '<<"MAX"<<NL;
    mopa[MP(a,v)] = MP(x,y);

    Dup(x-1,y-1,v);
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);

    int tc;

    cin>>tc;

    FOR(tt,1,tc)
    {
        mem(mat,0); mem(ans,0); mem(lev,0);
        mem(flow,0); mem(pa,0);
        int i, j, c, a=0, b=0, x, y;

        cin>>n>>m;

        FOR(i,1,n+m-1)
        {
            cin>>a; cnt = 0;

            ////cout<<0<<' '<<i<<' '<<a<<NL;

            x = min(n,i);
            y = max(0,i-x)+1;

            up(x,y,i);
            mat[0][i] = a - cnt;
        }

        FOR(i,1,n+m-1)
        {
            cin>>a;
            mat[n+m+i][2*(n+m)] = a; cnt = 0;
            ///cout<<n+m+i<<' '<<2*(n+m)<<' '<<a<<NL;

            x = min(n,i);
            y = i-x;
            if(i > n) y = m-y;
            else y = m;

            Dup(x,y,n+m+i);
            mat[n+m+i][2*(n+m)] = a-cnt;
        }

        des = 2*(n+m);
        FOR(i,0,des)
        FOR(j,0,des) thaka[i][j] = mat[i][j];
        MAX_flow(0);

        FOR(i,0,des)
        {
            FOR(j,0,des)
            {
                a = thaka[i][j] - mat[i][j];
                if(a > 0)
                {
                    PR dhor = mopa[MP(i,j)];
                    ans[dhor.F][dhor.S] += a;
                }
            }
        }

        cout<<"Case "<<tt<<":"<<NL;
        FOR(i,1,n)
        FOR(j,1,m)
        {
            cout<<ans[i][j]+1;
            if(j == m) cout<<NL;
            else cout<<' ';
        }

    }


}
