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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[200010], ans[200010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(ans,-1);
    int i,j,x,y,n,m,a,b,c;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];

    x=10000000;
    FOR(i,0,n-1)
    {
        if(ar[i]==0) x=i;
        ans[i]=max(x-i,i-x);
    }
    REV(i,n-1,0)
    {
       if(ar[i]==0) x=i;
       a=max(x-i,i-x);
       ans[i]=min(a,ans[i]);
    }
    FOR(i,0,n-1) cout<<ans[i]<<' ';
    return 0;
}
