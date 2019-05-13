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

vector<LL> mat[sz], con[sz], bap[sz], cost[sz], co[sz];
LL lev[sz], pa, cen, sub[sz], tr_sz, dis[sz], dhukao, ase[sz], copo[sz];
vector<LL>mx_d[sz];
vector<LL>::iterator low;

void col_info(LL p,LL vp)
{
    if(dhukao==1)
    {
        bap[p].PB(cen);
        cost[p].PB(dis[p]);
        mx_d[cen].PB(dis[p]);
        if(cen!=p) copo[p]=min(copo[p],dis[p]);
    }
    sub[p]=1;
    FOR(i,0,(LL)mat[p].size()-1)
    {
       LL v=mat[p][i];

       if(lev[pa]<lev[v]) pa=v;
       if(v==vp||lev[v]!=0) continue;

       dis[v]=dis[p]+co[p][i];
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
    LL i,j,n,m,a,b,x,y,t,v,z,c,k;

    cin>>n>>m;
    FOR(i,1,n-1)
    {
        cin>>a>>b>>c;
        mat[a].PB(b); mat[b].PB(a);
        co[a].PB(c); co[b].PB(c);
    }
    FOR(i,1,n) copo[i]=mod;

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
                ///cout<<pa<<' '<<x<<NL;
            }
        }

    FOR(i,1,n)sort(mx_d[i].begin(), mx_d[i].end());

//    ///cout<<NL;
//    FOR(i,1,n)
//    {
//        FOR(j,0,(LL)mx_d[i].size()-1)
//        {
//            a=mx_d[i][j];
//            ///cout<<a<<' ';
//        }
//        ///cout<<NL<<i<<' '<<copo[i]<<NL;
//    }
//    ///cout<<NL;
    FOR(l,1,m)
    {
        cin>>t>>v;

        z=0;
        REV(i,(LL)bap[t].size()-1,0)
        {
            x=bap[t][i];
            y=cost[t][i];
            k=v-y;

            if(x==0) break;
            low=upper_bound(mx_d[x].begin(),mx_d[x].end(),k);
            a=low-mx_d[x].begin(); a--;
            if(k<0) a=-1;

            low=upper_bound(mx_d[x].begin(),mx_d[x].end(),k-copo[x]-copo[x]);
            b=low-mx_d[x].begin(); b--;
            if(k-copo[x]-copo[x]<0) b=-1;
            z+=(a-b);

            ///cout<<v<<' '<<y<<' '<<k<<' '<<x<<' '<<copo[x]<<NL;
            ///cout<<k<<' '<<z-copo[x]-copo[x]<<' '<<' '<<a<<' '<<b<<NL;
        }
        if(z==mod) z=-1;
        cout<<z<<NL;


    }
    return 0;
}





