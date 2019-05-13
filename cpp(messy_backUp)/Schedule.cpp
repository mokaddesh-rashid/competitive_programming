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
#define sz 5010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    int l,r,p;
}ar[sz];

class Compare
{
public:
    bool operator()(node x,node y)
    {
        if(x.l==y.l) return x.r<y.r;
        else return x.l<y.l;
    }
};

int ans[sz], tp;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,x,y;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i].l>>ar[i].r, ar[i].p=i+1;
    sort(ar,ar+n,Compare());

    FOR(i,0,n-1)
    {
        a=0;
        FOR(j,0,n-2)
        {
            x=j; y=j+1;
            if(x==i) x++, y++;
            if(y==i) y++;
            if(x>=n||y>=n) continue;
            if(ar[x].r>ar[y].l) a=1;
        }
        if(a==0) ans[tp]=ar[i].p, tp++;
    }
    sort(ans,ans+tp);
    cout<<tp<<NL;
    FOR(i,0,tp-1) cout<<ans[i]<<' ';
    return 0;
}


