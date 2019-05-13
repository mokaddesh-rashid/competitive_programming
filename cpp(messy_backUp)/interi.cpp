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

int k,n,ck,l,dis[20][20];
int vis[20],bru[20],baki[20],br,ba,ase[20],order[20];
set<int> sota[MAX];

int ty;

void update()
{
    int  c=0,a=order[0],b=order[n-1],d,e;
    FOR(i,0,n-2) c+=dis[order[i]][order[i+1]];

    FOR(i,0,br-1)
        FOR(j,i+1,br-1)
        {
                d=l-c-dis[a][bru[i]]-dis[b][bru[j]];
                e=bru[i]+bru[j]*17;
                if(sota[e].find(d)!=sota[e].end())ck=1;
        }
}

void back_track(int p,int n)
{
    if(p==n&&ty==0)
    {
        int  c=0,a=order[0]+order[n-1]*17;
        FOR(i,0,n-2) c+=dis[order[i]][order[i+1]];
        sota[a].insert(c);
        return;
    }
    else if(p==n)
    {
        update();
        return;
    }

    FOR(i,0,n-1)
        if(ase[i]==0)
        {
            if(ty==0)order[p]=bru[i];
            else order[p]=baki[i];
            ase[i]=1;back_track(p+1,n);ase[i]=0;
        }
}

void chk()
{
    FOR(i,0,14*17)
    {
        while(!sota[i].empty())
        {
            sota[i].erase(sota[i].begin());
        }
    }
    br=ba=0;
    FOR(i,1,n)
    {
        if(vis[i])bru[br++]=i;
        else baki[ba++]=i;
    }
    ///cout<<br<<' '<<ba<<NL;
    ty=0; back_track(0,br);
    ty=1; back_track(0,ba);
}

void rec(int p,int v)
{
    if(v==k)
    {
        chk();
        return;
    }
    if(p>n)return;

    FOR(i,p,n) vis[i]=1,rec(i+1,v+1),vis[i]=0;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    cin>>n>>l; k=n/2;
    FOR(i,1,n)
        FOR(j,1,n)cin>>dis[i][j];

    if(n==2&&dis[1][2]+dis[2][1]==l)ck=1;
    else if(n==3)
    {
        if(dis[1][2]+dis[2][3]+dis[3][1]==l)ck=1;
        if(dis[1][3]+dis[3][2]+dis[2][1]==l)ck=1;
        if(dis[2][3]+dis[3][1]+dis[1][2]==l)ck=1;
    }
    else rec(1,0);
    if(ck)cout<<"possible"<<NL;
    else cout<<"impossible"<<NL;
    return 0;
}
