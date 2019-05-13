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
#define MAX 1000010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int  arr[MAX], pfac[20+1], tim[20+1], nf;

void sieve( LL n )
{
    LL  m=sqrt(n), i, j;
    for(i=2;i<=m;i++)
    {
        if(arr[i]==0)
         {
            for(j=i;j<=n;j+=i)
                arr[j]=i;
         }
    }
    for(i=3;i<=n;i+=2)
        if(arr[i]==0) arr[i]=i;
}

void prime_fac(LL n)
{
    while(n>1)   //for( LL  i=0; i<np && prime[i] <= m ; i++ )
    {
       if(pfac[nf-1]==arr[n])
           tim[nf-1]++;
       else
       {
           pfac[nf]=arr[n];
           tim[nf]=1; nf++;
       }
       n /= arr[n];
    }
}

vector<int> mat[MAX],cost[MAX];
int val[sz],ans[sz],cnt[sz];
pr foo[sz], soo[sz], rng[sz];

struct info
{
   int sum;

}tree[4*sz];

void update_node(int idx, int b, int e, int v)
{
    cnd.sum += v;
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;

    sieve(MAX-9);
    int i,j,a,b,c,x,y,z,n,m,p,v;

    cin>>n;
    FOR(i,0,n-1) cin>>val[i];
    FOR(i,0,n-1)
    {
        nf=0; prime_fac(val[i]); c=0;
        FOR(j,0,nf-1)
        {
            a=pfac[j]; b=tim[j];
            mat[a].PB(i); cost[a].PB(b);
            c+=b;
        }
        cnt[i]=c;
    }

    FOR(i,2,10)
    {
        z=mat[i].size();
        FOR(j,0,z-1)
        {
            a=mat[i][j]; b=cost[i][j];
            ///cout<<i<<' '<<a<<' '<<b<<NL;
        }
    }

    cin>>m;
    FOR(i,0,m-1)
    {
        cin>>rng[i].F>>rng[i].S;
        cin>>foo[i].F>>soo[i].F;
        foo[i].S=soo[i].S=i;

    }
    FOR(i,0,m-1)
    x=y=0; mem(tree,0);
    FOR(i,0,n-1) update(1,0,sz,i,i,cnt[i]);

    sort(foo,foo+m);
    FOR(i,0,m-1)
    {
       a=foo[i].F; b=foo[i].S;
       while(x<a)
       {
           z=mat[x].size();
           FOR(j,0,z-1)
           {
               p=mat[x][j]; v=cost[x][j];
               update(1,0,sz,p,p,v*-1);
           }
           x++;
       }
       ans[b]=query(1,0,sz,rng[b].F-1,rng[b].S-1);
       //cout<<b<<' '<<ans[b]<<' '<<rng[b].F-1<<NL;
    }

    x=y=0; mem(tree,0);
    FOR(i,0,n-1) update(1,0,sz,i,i,cnt[i]);

    ///FOR(i,0,m-1) cout<<soo[i].F<<NL;
    sort(soo,soo+m);
    FOR(i,0,m-1)
    {
       a=soo[i].F; b=soo[i].S;
       while(x<=a)
       {
           z=mat[x].size();
           FOR(j,0,z-1)
           {
               p=mat[x][j]; v=cost[x][j];
               update(1,0,sz,p,p,v*-1);
           }
           x++;
       }
       ans[b]-=query(1,0,sz,rng[b].F-1,rng[b].S-1);
       ///cout<<b<<' '<<ans[b]<<' '<<soo[i].F<<NL;
    }
    FOR(i,0,m-1) cout<<ans[i]<<NL;

}
