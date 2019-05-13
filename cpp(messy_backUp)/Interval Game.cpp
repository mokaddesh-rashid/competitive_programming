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

LL ar[300010], sr[220], sm[300010], dp[300010][220];
LL n, m;
LL rec(LL x, LL y)
{
    if(y==m) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    LL i, j, a, b, c, d;
    if(y==0) a=n-sr[y]+1;
    else a=sr[y-1]-sr[y]-1;
    LL temp;
    FOR(i,x,x+a-1)
    {
        if(i==0) b=sm[i+sr[y]-1];
        else b=sm[i+sr[y]-1]-sm[i-1];
        //cout<<y<<' '<<sr[y]<<' '<<i<<' '<<i+sr[y]-1<<' '<<b<<endl;
        if(y%2==0)
        {
            if(i==x) temp=b+rec(i+1,y+1);
            else temp=max(temp,b+rec(i+1,y+1));
        }
        else
        {
            if(i==x) temp=rec(i+1,y+1)-b;
            else temp=min(temp,rec(i+1,y+1)-b);

        }
    }
    return dp[x][y]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        FOR(i,0,n)
        FOR(j,0,m) dp[i][j]=-1;
        LL i, j, x=0, y;
        cin>>n>>m;
        FOR(i,0,n-1) cin>>ar[i], x+=ar[i], sm[i]=x;
        FOR(i,0,m-1) cin>>sr[i];
        x=rec(0,0);
        cout<<x<<endl;
    }
    return 0;
}


