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

struct info
{
   LL  v;

}tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.v=v;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.v;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
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
    cnd.v = max(tree[lnd].v,tree[rnd].v);
}

int ar[sz], hh[sz], ans[sz];
pr in[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,x,y,z;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>in[i].F;
        in[i].S=i;
        cin>>hh[i];
    }
    sort(in,in+n);
    FOR(i,0,n-1) ar[i]=in[i].F;

    REV(i,n-1,0)
    {
        a=in[i].F; b=in[i].S;
        a+=(hh[b]-1);
        ///cout<<in[i].F<<' '<<a<<NL;
        x=upper_bound(ar,ar+n,a)-ar;
        x--;
        //cout<<in[i].F<<' '<<i<<' '<<x<<NL;
        c=query(1,0,n-1,i,x);
        update(1,0,n-1,i,i,max(i+1,c));
        //cout<<max(i+1,c)<<NL;
        z=max(i+1,c);
        ans[b]=z-i;
    }
    FOR(i,0,n-1) cout<<ans[i]<<' ';
    return 0;
}


