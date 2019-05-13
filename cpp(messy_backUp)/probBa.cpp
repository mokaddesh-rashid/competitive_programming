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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[MAX][MAX],n,ar[MAX];

int rec(int p,int t)
{
    if(t==0)return 1;
    if(t<0||p<0)return 0;
    if(dp[p][t]!=-1)return dp[p][t];

    return dp[p][t]=rec(p-1,t)+rec(p,t-ar[p]);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n;
    cin>>n;
    FOR(tt,1,n)
    {
        mem(dp,-1);
        ar[0]=1;ar[1]=2;ar[2]=tt;
        //cout<<rec(2,183)<<NL;
        if(rec(2,n)==n)
        {
            cout<<n<<' '<<3<<NL;
            cout<<1<<' '<<2<<' '<<tt<<NL;
            return 0;
        }
    }
    return 0;
}


