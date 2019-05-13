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

string str, ss;
int n, m;
LL dp[10010][101];

LL rec(int x, int y)
{
    if(y==m) return 1;
    if(x==n) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    LL temp=0;
    if(str[x]==ss[y]) temp = rec(x+1,y+1);
    temp += rec(x+1,y);

    return dp[x][y]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(t,0,tc-1)
    {
        mem(dp,-1);
        int i, j, x, y;
        cin>>str>>ss;
        n=str.size();
        m=ss.size();
        cout<<rec(0,0)<<endl;
    }
    return 0;
}


