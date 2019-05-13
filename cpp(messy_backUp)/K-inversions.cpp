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
#define mod          1000000000
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[lev][idx]
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


LL ar[100010];
struct info
{
   LL sum;

}tree[12][3*MAX];

void update_node(int lev, int idx, int b, int e, LL v)
{
    cnd.sum=v;
}

LL query(int lev, int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lev, lnd, b, (b+e)/2, st, en);
    LL rgt = query(lev, rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int lev, int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(lev, idx, b, e, v);
        return ;
    }

    update(lev, lnd, b, (b+e)/2, st, en, v);
    update(lev, rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lev][lnd].sum+tree[lev][rnd].sum;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,a,b,c=0,n,m,k,x,y,z;

    cin>>n>>k;
    FOR(i,0,n-1) cin>>ar[i];

    REV(i,n-1,0)
    {
        FOR(l,0,k-1)
        {
           x=query(l,1,1,20000,0,ar[i]-1);
           if(l==0) x=1;
           update(l+1,1,1,20000,ar[i],ar[i],x);
           ///cout<<l<<' '<<x<<' '<<ar[i]<<NL;
           ///cout<<query(l+1,1,1,20000,ar[i],ar[i])<<NL;
        }

    }
    REV(i,n-1,0)
    {
        c+=query(k,1,1,n,ar[i],ar[i]);

    }
    cout<<c<<NL;
    return 0;
}
