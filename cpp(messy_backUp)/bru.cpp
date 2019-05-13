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
#define MX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[MX], cost[100]={6,2,5,5,4,5,6,3,7,6}, n;

int rec(int v)
{
    if(v==0) return 0;
    else if(v<0) return (1<<30);

    if(dp[v]!=-1) return dp[v];

    int temp=(1<<30), s=0;
    if(v==n) s=1;
    FOR(i,s,9)
        temp=min(temp,1+rec(v-cost[i]));
    return dp[v]=temp;
}

void prin(int v)
{
    if(v==0) return;
    else if(v<0) return;

    int s=0;
    if(v==n) s=1;
    FOR(i,s,9)
    {
        if(rec(v)==1+rec(v-cost[i]))
        {
            cout<<i;
            return prin(v-cost[i]);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m;

    cin>>n;
    m=rec(n);

    if(m==(1<<30)) cout<<-1<<NL;
    else if(n==6) cout<<0<<NL;
    else prin(n);
    return 0;
}

