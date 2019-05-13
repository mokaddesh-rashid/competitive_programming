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

int dp[10001], n, k, ar[10001], ct[10001], next[10001];

int rec(int x, int y)
{
    //cout<<x<<' '<<endl;
    if(y==0) return 1;
    if(y<0) return 0;
    if(x==n) return 0;
    if(dp[y]!=-1) return dp[y];
    return dp[y]=(rec(x,y-ar[x])+rec(x+1,y))%100000007;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        mem(dp,-1);
        int i, j, x=0, y, a=0;
        cin>>n>>k;
        sort(ar,ar+n);
        FOR(i,0,n-1) cin>>ar[i];
        x=rec(0,k);
        cout<<"Case "<<t<<": "<<x<<endl;
    }
    return 0;
}


