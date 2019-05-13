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
#define MAX 200010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   int val;

}tree[4*MAX];
int arr[100010];

void init(int idx, int b, int e )
{
    if( b == e )
    {
        cnd.val = arr[b];
        return ;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.val =  __gcd(tree[lnd].val,tree[rnd].val);
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

    int lft = query(lnd, b, (b+e)>>1, st, en);
    int rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return __gcd(lft,rgt);
}

int dp[MAX];

int rec(int p)
{
    ///cout<<p<<NL;
    if(p==0) return 1;
    if(dp[p]!=-1) return dp[p];

    int temp=0;
    FOR(i,1,p)
    {
        int x=query(1,1,MAX,p-i+1,p);
        if(x>1) temp+=rec(p-i), temp%=mod;
        else break;
    }
    return dp[p]=temp%mod;
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,n,m,a,b,c;

    cin>>n;
    FOR(i,1,n) cin>>arr[i], arr[i+n]=ar[i];
    init(1,1,MAX);
    ///cout<<query(1,1,n,3,3)<<NL;
    x=rec(n);
    return 0;
}


