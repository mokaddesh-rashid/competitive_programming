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
#define M_PI           3.14159265358979323846
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[sz], con[sz], bap[sz], cost[sz];
int lev[sz], pa, cen, sub[sz], tr_sz, dis[sz], dhukao, ase[sz];
multiset<int>mx_d[sz];
multiset<int>::iterator it;

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
       sub[p]+=sub[v];
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

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,x,y,t,v,z;

    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    FOR(l,1,18)
        FOR(i,1,n)
        {
            if(lev[i]==0)
            {
                dhukao=pa=0; col_info(i,i);
                tr_sz=sub[i]; x=centroid(i,i);

                dis[x]=0; dhukao=1; cen=x; col_info(x,x);
                lev[x]=lev[pa]+1;
                con[pa].PB(x); con[x].PB(pa);
            }
        }

    cin>>m;
    FOR(l,1,m)
    {
        cin>>t>>v;
        if(t==0)
        {
            if(ase[v]==0)
            {
                FOR(i,0,(int)bap[v].size()-1)
                {
                    x=bap[v][i];
                    y=cost[v][i];
                    mx_d[x].insert(y);
                }
                ase[v]=1;
            }
            else
            {
                FOR(i,0,(int)bap[v].size()-1)
                {
                    x=bap[v][i];
                    y=cost[v][i];
                    mx_d[x].erase(mx_d[x].find(y));
                }
                ase[v]=0;
            }
        }
        else
        {
            z=mod;
            FOR(i,0,(int)bap[v].size()-1)
            {
                x=bap[v][i];
                y=cost[v][i];

                if(!mx_d[x].empty())
                {
                    it=mx_d[x].begin();
                    a=*it;
                    z=min(z,a+y);
                }
            }
            if(z==mod) z=-1;
            cout<<z<<NL;
        }

    }
    return 0;
}




