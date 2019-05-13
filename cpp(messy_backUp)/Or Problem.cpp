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
   int sum;

}tree[4*MAX];
int nxt[MAX][21],value[MAX][21];
int ar[MAX],n,k;


void init(int idx, int b, int e )
{
    if( b == e )
    {
        cnd.sum = ar[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum =  tree[lnd].sum ^ tree[rnd].sum ;
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft^rgt);
}

LL dp[MAX], c, tim[MAX], ti;

LL rec(int p)
{
    if(p==n)return 0;
    if(tim[p]==ti) return dp[p];

    LL temp=max(ar[p]+rec(p+1)-c,(LL)-1), v;
    FOR(i,0,20)
    {
        int x=nxt[p][i];
        int y=value[p][i];///query(1,0,n-1,p,x);
        ///cout<<p<<' '<<x<<NL;
        v=y+rec(x+1)-c;
        temp=max(temp,v);
    }

    tim[p]=ti;
    return dp[p]=temp;
}

int back_track(int p)
{
    ///cout<<p<<NL;
    if(p==n)return 0;
    ///cout<<p<<NL;

    int temp=0;
    if(rec(p)==ar[p]+rec(p+1)-c) return 1+back_track(p+1);
    FOR(i,0,20)
    {
        int x=nxt[p][i];
        int y=query(1,0,n-1,p,x);
        if(dp[p]==y+rec(x+1)-c) return 1+back_track(x+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,p;
    LL st,en,ret=0,x,y,z;

    cin>>n>>k;
    FOR(i,0,n-1)cin>>ar[i];
    init(1,0,n-1);

    FOR(i,0,20)
    {
        p=n-1;
        REV(j,n-1,0)
        {
            nxt[j][i]=p; value[j][i]=query(1,0,n-1,j,p);
            if(ar[j]&(1<<i))p=j;
        }
    }

    st=0; en=1<<21;

    ///while(st<=en)
    FOR(i,1000,2500)
    {
        ti++;
        c=(st+en)/2; c=i;
        x=rec(0); y=back_track(0);
        //cout<<i<<' '<<x<<' '<<y<<' '<<x+y*c<<NL;
        if(y<=k) ret=max(ret,x+y*c),en=c-1;
        else st=c+1;
    }
    cout<<i<<' '<<x<<' '<<y<<' '<<x+y*c<<NL;
    cout<<ret<<NL;
    return 0;
}


