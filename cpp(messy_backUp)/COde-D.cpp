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
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL pa[MAX],dis[MAX];
vector<LL>mat[MAX],sum[MAX];

void up(LL p)
{
    LL c=0;
    FOR(i,0,(LL)mat[p].size()-1)
    {
        c+=mat[p][i];
        sum[p].PB(c);
    }
}

LL query(LL p,LL h)
{
    LL c=0,v;
    LL pos,x;

    while(p>=1)
    {
        pos=*(upper_bound(mat[p].begin(),mat[p].end(),h)); pos--;
        x=(LL)mat[p].size()-1;
        if(mat[p][x]<=h)pos=x;
        while(pos>=0)
        {
            if(mat[p][pos]>h)pos--;
            else break;
        }

        ///cout<<pos<<' '<<p<<' '<<h<<' '<<mat[p].size()<<NL;
        if(pos>=0)c+=(h*(pos+1)-sum[p][pos]);
        ///cout<<c<<NL;
        if(p>1)
        {
            h-=(dis[p]*2);
            pos=*(upper_bound(mat[p].begin(),mat[p].end(),h)); pos--;
            x=(LL)mat[p].size()-1;
            if(mat[p][x]<=h)pos=x;
//            while(pos>=0)
//            {
//                if(mat[p][pos]>h)pos--;
//                else break;
//            }
            ///cout<<h<<' '<<pos<<NL;
            if(pos>=0)c-=(h*(pos+1)-sum[p][pos]);
        }
        ///cout<<c<<NL<<NL;
        h+=dis[p];
        p/=2;
    }

    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j,n,m,x,y,p,q,h;

    cin>>n>>q;

    FOR(i,2,n)cin>>dis[i];
    FOR(i,1,n)mat[i].PB(0);

    FOR(i,2,n)
    {
        LL c=0,p=i;

        while(p>1)
        {
            x=p; y=p/2;
            c+=dis[x];
            mat[y].PB(c);
            ////cout<<y<<' '<<c<<NL;
            p=y;
        }
    }
    ////cout<<NL<<NL;

    FOR(i,1,n) sort(mat[i].begin(),mat[i].end());
    FOR(i,1,n)up(i);
    FOR(i,1,q)
    {
        cin>>p>>h;
        cout<<query(p,h)<<NL;
    }
    return 0;
}


