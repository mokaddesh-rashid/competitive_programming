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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<LL> tim[sz];

LL nex(LL p,LL c)
{
    LL i,j,n,x,y,st,en,mid,a,b;

    n=tim[p].size();

    st=0; en=n-1; x=-1;
    while(st<=en)
    {
        mid=(st+en)>>1;
        if(tim[p][mid]==c)
        {
          x=mid;
          break;
        }
        else if(tim[p][mid]<c) st=mid+1;
        else en=mid-1;
    }

    if(x==-1) return x;

    st=x; en=n-1; y=x;
    while(st<=en)
    {
        mid=(st+en)>>1;
        a=tim[p][mid]; b=tim[p][x];
        ///cout<<a<<' '<<b<<' '<<mid<<' '<<x<<NL;
        if(a-b==mid-x)
        {
            st=mid+1;
            y=max(y,tim[p][mid]);
        }
        else en=mid-1;
    }

    return y;

}

struct node
{
    LL v, l, m, pa, p;
}dij[100010];

class compare
{
    public:
        bool operator()( node f, node s )
        {
            return f.v > s.v;
        }

};
priority_queue< node, vector<node>, compare > mq;
vector<LL> mat[100010], cost[100010];
node exo;

void dijkstra( LL p )
{
    dij[p].v = 0; dij[p].l = 0; dij[p].pa = -1;
    exo.p = p;
    exo.v = dij[p].v;
    mq.push( exo );

    while( !mq.empty() )
    {
        p = mq.top().p;
        mq.pop();

        for( LL i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i], y, z;

            y=dij[p].v;
            z=nex(p,y);
            if(z!=-1) y=z+1;

            if( dij[x].v > cost[p][i] + y )
            {
                dij[x].v = cost[p][i] + y;
                dij[x].pa = p;
                exo.p = x; exo.v = dij[x].v;
                mq.push( exo );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    mem(dij,0);
    LL i, j, x, y, z, n, m, k, a, b;

    cin>>n>>m;
    FOR(i,1,n) dij[i].v = maxx;

    FOR(i,1,m)
    {
        cin>>x>>y>>z;
        mat[x].PB(y); cost[x].PB(z);
        mat[y].PB(x); cost[y].PB(z);
    }
    FOR(i,1,n)
    {
        cin>>k;
        FOR(j,1,k)
        {
            cin>>a;
            if(tim[i].size()==0)tim[i].PB(a);
            else if(a!=tim[i][(int)tim[i].size()-1]) tim[i].PB(a);
        }
    }
    dijkstra(1);
    if(dij[n].v==maxx) cout<<-1<<NL;
    else cout<<dij[n].v<<NL;

    return 0;

}


