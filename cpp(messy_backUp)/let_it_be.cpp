#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
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
#define MAX 2000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL n,m,p,q,dr[MAX],er[MAX],prin[50];
pr ar[MAX],br[MAX];
struct info
{
    LL first,second,p;
}nd[MAX],ase[MAX];
vector<LL>mat[MAX],sat[MAX];

class Compare
{
public:
    bool operator()(info x,info y)
    {
        if(x.F==y.F) return x.S<y.S;
        else return x.F<y.F;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,v,low,up,ans=MAX,too=0;
    LL a,b,c,d;

    cin>>v;
    n=v/2; m=v-n;
    FOR(i,0,n-1)cin>>ar[i].F>>ar[i].S;
    FOR(i,0,m-1)cin>>br[i].F>>br[i].S;

    LL np=1<<n;
    FOR(i,0,np-1)
    {
        d=c=0;
        FOR(j,0,n-1)
        {
            if(i&(1<<j))
            {
                c+=ar[j].F; mat[i].PB(0); d++;
            }
            else
            {
                c-=ar[j].S; mat[i].PB(1); d--;
            }
        }
        nd[i].F=c; nd[i].S=d; nd[i].p=i;
       /// cout<<c<<NL;
    }

    sort(nd,nd+np,Compare());
    FOR(i,0,np-1)
    {
        dr[i]=nd[i].F;
        er[i]=nd[i].S;
    }

    FOR(i,0,(1<<m)-1)
    {
        d=c=0;
        FOR(j,0,m-1)
        {
            if(i&(1<<j))
            {
                c-=br[j].F; d--;
            }
            else
            {
                c+=br[j].S; d++;
            }
        }
     ///   cout<<c<<NL;
        low=lower_bound(dr,dr+np,c)-dr;
        up=upper_bound(dr,dr+np,c)-dr;
       // cout<<dr[low]<<NL<<NL;
        if(dr[low]==c)
        {
            v=lower_bound(er+low,er+up,d)-er;
            FOR(i,max((LL)0,v-10),min(up-1,v+10))
            {
                if(dr[i]==c)
                {
                    if(abs(d-er[i])<ans)
                    {
                        too=1;
                        p=nd[i].p;
                        ans=abs(d-er[i]);

                        FOR(j,0,n-1)
                        {
                            prin[j]=mat[p][j];
                        }
                        FOR(j,0,m-1)
                        {
                            if(i&(1<<j))prin[j+n]=1;
                            else prin[j+n]=0;
                        }
                    }
                }
            }

        }

    }

    if(too)
    FOR(i,0,n+m-1)cout<<prin[i];
    else cout<<-1<<NL;

    return 0;
}


