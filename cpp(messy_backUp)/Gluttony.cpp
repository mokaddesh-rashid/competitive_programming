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
#define MAX 100000
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL pa[MAX],cnt,n,vis[MAX];
LL ar[MAX],br[MAX];


LL fi_pa( LL x )
{

    if( pa[x] == x ) return x;
    else return fi_pa( pa[x] );
}

bool can(LL p,LL v)
{
    if(p==v||vis[v]==1)return false;

    LL x=fi_pa(p);
    LL y=fi_pa(v);

    if(x==y)return false;
    else return true;
}

LL chk()
{
    FOR(i,1,(1<<n)-2)
    {
        LL c=0,d=0;
        FOR(j,0,n-1)
        {
            if(i&(1<<j))
                c+=ar[j+1], d+=br[j+1];
        }
        if(c==d) return 0;
    }
    return 1;
}

void rec(LL p)
{
    if(cnt)return;
    if(p==n)
    {
        FOR(i,1,n)
            if(vis[i]==0)
              {
                pa[p]=i; vis[i]=1;
                FOR(i,1,n)br[i]=ar[pa[i]];

                if(chk()) cnt++;
                else pa[p]=p, vis[i]=0;
              }
        return;
    }

    FOR(i,1,n)
    {
        if(can(p,i))
        {
           pa[p]=i; vis[i]=1;
           rec(p+1);
           if(cnt==0) pa[p]=p,vis[i]=0;
        }
    }
}


LL cr[MAX],dr[MAX];

void change()
{
    FOR(i,1,n)
        FOR(j,1,n)
            if(cr[i]==ar[j]) dr[i]=br[j];

    FOR(i,1,n)ar[i]=cr[i],br[i]=dr[i];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j;
    cin>>n;
    FOR(i,1,n)ar[i]=i,cr[i]=ar[i];
    sort(ar+1,ar+n+1);
    FOR(i,1,n)pa[i]=i;
    rec(1);

    if(cnt)
    {
        change();
        FOR(i,1,n)cout<<dr[i]<<' ';
    }
    else cout<<-1<<NL;
    ///cout<<chk()<<NL;
    return 0;
}


