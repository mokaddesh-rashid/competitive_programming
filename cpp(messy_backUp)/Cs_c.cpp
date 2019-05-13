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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX];

struct info
{
   LL val;

}tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.val = v;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

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

    cnd.val = max(tree[lnd].val,tree[rnd].val);
}

map<int,int>mopa;
int br[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c=0,x,y,ans=0;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i],br[i]=ar[i];
    sort(br,br+n);


    FOR(i,0,n-1)
        if(mopa[br[i]]==0)mopa[br[i]]=++c;
    FOR(i,0,n-1)
        ar[i]=mopa[ar[i]];

    FOR(i,0,n-1)cout<<ar[i]<<' ';
    cout<<NL;

    REV(i,n-1,0)
    {
       x=ar[i];
       y=query(1,1,MAX,x+1,MAX);
       ans=max(ans,y+1);
       update(1,1,MAX,x,x,y+1);
       cout<<x<<' '<<y+1<<NL;
    }

    cout<<n-ans<<NL;


    return 0;
}
