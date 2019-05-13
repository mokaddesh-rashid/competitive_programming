#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>
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
#define minn          (long long)-2147483648
#define maxx          (long long) 2147483647
#define mod          1000000007
#define LL           long long
#define NL "\n"
#define MAX 1000005
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

struct info
{
   int mn, mx;

}tree[4*MAX];
int arr[1000010];

void init(int idx, int b, int e )
{
    if( b == e )
    {
        cnd.mn=cnd.mx=arr[b];
        return ;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.mn=min(tree[lnd].mn,tree[rnd].mn);
    cnd.mx=max(tree[lnd].mx,tree[rnd].mx);    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}
info aw;
info query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return aw;
    if(st <= b && en >= e)
        return cnd;
    info ret;
    info lft = query(lnd, b, (b+e)>>1, st, en);
    info rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    ret.mn=min(lft.mn,rgt.mn);
    ret.mx=max(lft.mx,rgt.mx);
    return ret;
}
int ans[1000010];
int main()
{
    aw.mn=maxx; aw.mx=minn;
    int n,m,i,j,a,b,c,x,y,z,k;
    sff(n,k);//cin>>n>>k;
    FOR(i,1,n)sf(arr[i]);//cin>>arr[i];
    init(1,1,n);
    FOR(i,1,n-k+1)
    {
        info ole=query(1,1,n,i,i+k-1);
        pf("%d",ole.mn);
        if(i!=n-k+1) pf(" ");
        ans[i]=ole.mx;
    }
    pf(NL);
    FOR(i,1,n-k+1)
    {
        pf("%d",ans[i]);
        if(i!=n-k+1) pf(" ");
    }
    pf(NL);
    return 0;
}

