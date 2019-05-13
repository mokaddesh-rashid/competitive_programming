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
#define MAX 10010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[MAX], bap[MAX], cost[MAX];
int lev[MAX], pa, cen, sub[MAX], tr_sz, dis[MAX], dhukao, col[MAX], t_cen;
struct info
{
    int cnt[2],col[2],pcol[2];
}in[MAX];

void col_info(int p,int vp)
{
    if(dhukao==1)
    {
        bap[p].PB(cen);
        cost[p].PB(dis[p]);
    }
    sub[p]=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
       int v=mat[p][i];

       if(lev[pa]<lev[v]) pa=v;
       if(v==vp||lev[v]!=0) continue;

       dis[v]=dis[p]+1;
       col_info(v,p);
       sub[p]+=sub[v];///adding child`s sub tree
    }
}

int centroid(int p,int vp)
{
    if(sub[p]<=tr_sz>>1) return vp;

    FOR(i,0,(int)mat[p].size()-1)
    {
        int v=mat[p][i];
        if(sub[v]>tr_sz>>1 && lev[v]==0 && v!=vp ) return centroid(v,p);
    }
    return p;
}

void centroid_create(int n)
{
    int x;
    FOR(l,1,18)
        FOR(i,1,n)
        {
            if(lev[i]==0)
            {
                dhukao=pa=0; col_info(i,i);
                tr_sz=sub[i]; x=centroid(i,i);

                dis[x]=0; dhukao=1; cen=x; col_info(x,x);
                lev[x]=lev[pa]+1;
                ///if(pa==0) t_cen=x;
                //else con[pa].PB(x); con[x].PB(pa);
            }
        }
}


int ty[MAX];

void color_update(int p)
{
    int x,y;

    FOR(i,0,(int)bap[p].size()-1)
    {
        x=bap[p][i];
        y=cost[p][i];
        in[x].col[ty[p]]+=y;

        if(i!=0)
        {
            y=cost[p][i-1];
            in[x].pcol[ty[p]]+=y;
        }

        in[x].cnt[ty[p]]++;
    }
}

void color_delete(int p)
{
    int x,y;

    FOR(i,0,(int)bap[p].size()-1)
    {
        x=bap[p][i];
        y=cost[p][i];
        in[x].col[ty[p]]-=y;

        if(i!=0)
        {
            y=cost[p][i-1];
            in[x].pcol[ty[p]]-=y;
        }

        in[x].cnt[ty[p]]--;
    }
}

int node_query(int p)
{
    int  c=0,a,b,x,y;

    FOR(i,0,(int)bap[p].size()-1)
    {
        x=bap[p][i]; y=cost[p][i];
        c+=in[x].col[ty[p]];
        c-=in[x].pcol[ty[p]];

        a=in[x].cnt[ty[p]];
        if(i!=(int)bap[p].size()-1)a-=in[bap[p][i+1]].cnt[ty[p]];
        c+=(a*y);
    }

    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,x,y,t,v,z,k,c=0;

    cin>>n>>k;
    FOR(i,1,n)cin>>ty[i];
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }

    centroid_create(n);
    FOR(i,1,n)color_update(i);

    FOR(q,1,k)
    {
        cin>>a>>b;
        if(a==1)
        {
            color_delete(b);
            ty[b]=(ty[b]+1)%2;
            color_update(b);
        }
        else cout<<node_query(b)<<NL;
    }
    return 0;
}


