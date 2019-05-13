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
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int dp[2010][2010],n,m;
string str, ss;

int rec(int x,int y)
{
    int temp=0, c=0;
    if(x>n||y>m) return dp[x][y]=0;
    if(x==n&&y==m) return dp[x][y]=1;
    if(dp[x][y]!=-1) return dp[x][y];
    if(y==m&&x<n&&str[x]=='*') return dp[x][y]=rec(x+1,y);
    if(x==n&&y<m&&ss[y]=='*') return dp[x][y]=rec(x,y+1);
    if(x>=n||y>=m) return dp[x][y]=0;
    int t=4;
    if(str[x]=='*')
        {
            FOR(i,0,t)
            {
                if(ss[y+i]=='*') t++;
                if(y+i>m) break;
                dp[x][y]=max(dp[x][y],rec(x+1,y+i));
            }
            c=1;
        }
    t=4;
    if(ss[y]=='*')
        {
            FOR(i,0,t)
            {
                if(str[x+i]=='*') t++;
                if(x+i>n) break;
                dp[x][y]=max(dp[x][y],rec(x+i,y+1));
            }
            c=1;
        }
    if(str[x]==ss[y]) dp[x][y]=max(dp[x][y],rec(x+1,y+1)), c=1;
    if(c==0) dp[x][y]=0;
    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(dp,-1);
        int i, j, x, y;
        cin>>str>>ss;
        n=str.size(); m=ss.size();
        x=rec(0,0);
        if(x==1) cout<<"Case #"<<tt<<": TRUE"<<NL;
        else cout<<"Case #"<<tt<<": FALSE"<<NL;
    }
    return 0;
}
