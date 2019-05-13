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

vector<int> mat[sz];
int dp[sz],ar[sz],n;

int rec(int x)
{
    if(x==n) return 0;
    if(dp[x]!=-1) return 0;

    int a,b,c,l=0,temp=0;
    FOR(i,x+1,n)
    {
        if(x==0||abs(ar[x]-ar[i])<=1||ar[x]%7==ar[i]%7)
            temp=max(temp,1+rec(i));
    }

    FOR(i,x+1,n)
    {
        if(x==0||abs(ar[x]-ar[i])<=1||ar[x]%7==ar[i]%7)
            c=1+rec(i);
        if(c==temp) mat[x].PB(i);
    }

    return dp[x]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y,m;

    cin>>n;
    FOR(i,1,n) cin>>ar[i];
    x=rec(0);
    cout<<x<<NL;
    return 0;
}


