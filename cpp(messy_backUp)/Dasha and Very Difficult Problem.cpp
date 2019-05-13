#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

pr ar[100010];
int br[100010], ans[100010];

int chk(int x, int y, int lim)
{
    int st=-1000000000, en=x, mid, re;
    re=st;

    while(st<=en)
    {
        mid=(st+en)/2;
        if(mid+y<=lim) st=mid+1, re=max(re,mid);
        else en=mid-1;
    }
    return re;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, l, r, a, b, c=0, d=100000000000;
    cin>>n>>l>>r;
    FOR(i,0,n-1) cin>>br[i];
    FOR(i,0,n-1) cin>>ar[i].F, ar[i].S=i;
    sort(ar,ar+n, greater<pr>());
    FOR(i,0,n-1)
    {
        a=ar[i].S;
        if(i==0) x=r-br[a];
        x=chk(x,br[a],r);
        if(br[a]+x>r||br[a]+x<l) c=1;
        //cout<<a<<' '<<x<<endl;
        ans[a]=br[a]+x;
        x--;
    }
    if(c==1) cout<<-1;
    else
    {
        FOR(i,0,n-1) cout<<ans[i]<<' ';
    }
    return 0;
}


