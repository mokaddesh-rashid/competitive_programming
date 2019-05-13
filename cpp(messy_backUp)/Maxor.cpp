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
#define MAX 1000010
#define SZ 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX],cnt[MAX],ase[MAX],dp[20][MAX],vis[MAX],tim;

int rec(int p,int x)
{
    if(p==18)return 0;
    if(dp[p][x]!=-1)return dp[p][x];

    int temp=ase[x];
    FOR(i,p,17)
    {
        if(((1<<i)&x)==0)
        {
            int a=(1<<i)|x;
            temp+=rec(i+1,a);
        }
    }
    return dp[p][x]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    mem(cnt,0); mem(vis,-1); mem(dp,-1);
    int i,j,n,x=-1,a;
    LL c=0;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i],ase[ar[i]]++;
    sort(ar,ar+n,greater<int>());

    FOR(i,0,n-1)
    {
        if(cnt[i]==0)
        FOR(j,i+1,n-1)
        {
            c=ar[i]|ar[j];
            if(c==ar[i]||c==ar[j])cnt[j]=1;

            if(c>x)x=c;
        }
    }
    c=0;
    FOR(i,0,n-1)
    {
        a=x-ar[i];

        if(a==0) c+=(n-1);
        else c+=rec(0,a),tim++;
    }
    cout<<x<<' '<<c/2<<NL;

    return 0;
}


