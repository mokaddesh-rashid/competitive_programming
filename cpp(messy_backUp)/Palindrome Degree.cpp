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
#define M1          1000000007
#define M2          100000007
#define B1          107
#define B2          31
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 5000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

int cnt[MAX];
string str;

void info()
{
    LL x=1,y=1,n=str.size(),a=0,b=0,c=0,d,p;
    FOR(i,0,n-1)///po[n-i].S=po[i].F=x, x*=B1;
    {
        p=str[i]-'0';p++;
        c=p*x; d=p;
        a+=c; b+=d;
        if(a==b)cnt[i]=1;
        x*=B1; b*=B1;
    }

}
int dp[MAX];
int rec(int r)
{
    if(r==0) return 1;
    if(dp[r]!=-1) return dp[r];
    if(cnt[r])
    {
        //cout<<r<<NL;
        if(r%2) return dp[r]=1+rec(r/2);
        else return dp[r]=1+rec(r/2-1);
    }
    else return dp[r]=0;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);

    int i,j,n,m;
    LL a,b,c=0,x,y,z;
    pr d,e;

    cin>>str; n=str.size();
    info();
    FOR(i,0,n-1)c+=rec(i);
    cout<<c<<NL;
    return 0;
}



