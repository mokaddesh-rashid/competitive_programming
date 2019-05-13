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
#define MAX 200010
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   int v;

}tree[4*MAX];
int arr[200010];

void init(int idx, int b, int e )
{
    if( b == e )
    {
        cnd.v = arr[b];
        return ;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.v =  min(tree[lnd].v,tree[rnd].v);
    //cout << cnd.v << ' ' << b <<  ' ' << e << endl;
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return mod;
    if(st <= b && en >= e)
        return cnd.v;

    int lft = query(lnd, b, (b+e)>>1, st, en);
    int rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return min(lft,rgt);
}

int ans[200010];
int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    unsigned ans=1;
    pf("%d ",ans);/// cout<<ans[i]<<' ';
    return 0;
}
