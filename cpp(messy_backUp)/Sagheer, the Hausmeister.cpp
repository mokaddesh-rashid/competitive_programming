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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str;
int lf[sz], rg[sz], ase[sz], n, m;
int dp[16][110][1600];

int rec(int x,int y,int z)
{
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(y==0)
    {
        int a,b,c,d=mod;
        a=rg[x]*2; b=m+1; c=z-ase[x];
        if(c==0) return dp[x][y][z]=rg[x];
        else
        {
            d=min(d,1+a+rec(x-1,0,c));
            d=min(d,1+b+rec(x-1,1,c));
            return dp[x][y][z]=d;
        }
    }
    else
    {
        int a,b,c,d=mod;
        a=m+1; b=lf[x]*2; c=z-ase[x];
        if(c==0) return dp[x][y][z]=lf[x];
        else
        {
            d=min(d,1+a+rec(x-1,0,c));
            d=min(d,1+b+rec(x-1,1,c));
            return dp[x][y][z]=d;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y,a,b,c=0,cnt=0, z=0;

    cin>>n>>m;
    FOR(i,0,n-1)
    {
        cin>>str;
        a=b=-1; x=0;
        FOR(j,0,m+1)
        {
            if(a==-1&&str[j]=='1') a=j, b=j;
            if(str[j]=='1') b=j, x++;
        }
        cnt+=x; ase[i]=x; lf[i]=m-a+1; rg[i]=b;
        if(a==-1) lf[i]=0,rg[i]=0;
        ///cout<<x<<' '<<m-a+1<<' '<<b<<NL;
    }
    ///cout<<cnt<<NL;

//    if(cnt==0)
//    {
//        cout<<0<<NL;
//        return 0;
//    }
    x=rec(n-1,0,cnt);
    cout<<x<<NL;
    return 0;
}


