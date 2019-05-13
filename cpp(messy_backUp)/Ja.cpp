#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

vector<LL> mat[sz], con[sz], bap[sz], cost[sz], dure[sz];
LL lev[sz], pa, cen, sub[sz], tr_sz, dis[sz], dhukao, ase[sz], t_cen;
vector<LL> child[sz], pachi[sz];

void col_info(LL p,LL vp)
{
    if(dhukao==1)
    {
        ///cout<<cen<<' '<<p<<NL;
        LL a=(LL)cost[p].size()-1;
        if(a>=0) pachi[cen].PB(cost[p][a]);
        bap[p].PB(cen);
        cost[p].PB(dis[p]);
        child[cen].PB(dis[p]);
    }
    sub[p]=1;
    FOR(i,0,(LL)mat[p].size()-1)
    {
       LL v=mat[p][i];

       if(lev[pa]<lev[v]) pa=v;
       if(v==vp||lev[v]!=0) continue;

       dis[v]=dis[p]+dure[p][i];
       col_info(v,p);
       sub[p]+=sub[v];
    }
}

LL centroid(LL p,LL vp)
{
    if(sub[p]<=tr_sz>>1) return vp;

    FOR(i,0,(LL)mat[p].size()-1)
    {
        LL v=mat[p][i];
        if(sub[v]>tr_sz>>1 && lev[v]==0 && v!=vp ) return centroid(v,p);
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,n,m,a,b,c,x,y,t,v,z,k,q;

    cin>>n>>q;
    FOR(i,1,n-1)
    {
        cin>>a>>b>>c;
        mat[a].PB(b); mat[b].PB(a);
        dure[a].PB(c); dure[b].PB(c);
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
                if(pa==0) t_cen=x;
            }
        }
    FOR(i,1,n) sort(child[i].begin(),child[i].end());
    FOR(i,1,n) sort(pachi[i].begin(),pachi[i].end());

    FOR(t,1,q)
    {
        cin>>i>>k;
        c=0;
        REV(j,(LL)bap[i].size()-1,0)
        {
            a=bap[i][j]; v=k-cost[i][j];

            vector<LL>::iterator low,up;
            low=child[a].begin();
            up=upper_bound (child[a].begin(), child[a].end(), v);

            c+=(up-low);
            ///cout<<a<<' '<<v<<' '<<' '<<(up-low)<<NL;
            if(a!=t_cen)
            {
                v=k-(cost[i][j-1]);

                low=pachi[a].begin();
                up=upper_bound (pachi[a].begin(), pachi[a].end(), v);

                c-=(up-low);
                ///cout<<bap[i][j-1]<<' '<<v<<' '<<(up-low)<<NL;
            }
        }
        cout<<c<<NL;
    }

    ///cout<<c/2<<NL;

    return 0;
}

