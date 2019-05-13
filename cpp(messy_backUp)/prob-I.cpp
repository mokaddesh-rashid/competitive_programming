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
#define mod          10056
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

LL ncr[MAX][MAX];

LL nCr(int n, int r)
{
    if(r == n || r == 0) return 1;
    if(r == 1) return n;
    if(ncr[n][r] != -1) return ncr[n][r];

    return ncr[n][r] = ((nCr(n-1, r) + nCr(n-1, r-1))%mod);
}

LL dp[MAX];
LL rec(int n)
{
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];

    LL temp,Btemp=0;
    FOR(i,1,n){
        temp=nCr(n,i)*rec(n-i);
        Btemp+=temp;
        Btemp%=mod;
    }
    return dp[n]=Btemp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);mem(ncr,-1);
    int tc;

    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,n,m;

        cin>>n;
        cout<<"Case "<<tt<<": "<<rec(n)<<NL;
    }
    return 0;
}



