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

LL dp[1010][1010];
int n;
pr ar[10010];

LL rec(int x, int y)
{
    if(x==n&&y>=0) return 0;
    if(y<=0) return maxx;
    if(dp[x][y]!=-1) return dp[x][y];
    LL temp=maxx, d;
    int a, b, c, fe, se, fs, ss;
    a=b=c=-1;
    FOR(i,x,n)
    {
        if(ar[i].S==1&&a==-1) a=i;
        if(ar[i].S==2&&b==-1) b=i;
        if(ar[i].S==1) fe=i;
        if(ar[i].S==2) se=i;
        if(a!=-1&&b!=-1) c=1;
        d=(ar[i].F-ar[x].F)+1;
        if(c==1)
        {
            fs=(ar[fe].F-ar[a].F)+1;
            ss=(ar[se].F-ar[b].F)+1;
            temp=min(temp, d*2+rec(i+1,y-1));
            temp=min(temp, fs+ss+(rec(i+1,y-2)));

        }
        else temp=min(temp, d+rec(i+1,y-1));
    }
    return dp[x][y]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int t;
    cin>>t;
    FOR(tt,0,t-1)
    {
        mem(dp,-1);
        int i, j, x, y, m, k, p;
        cin >>n>>k>>p;
        FOR(i,0,n-1) cin>>ar[i].S>>ar[i].F;
        sort(ar, ar+n);
        cout<<rec(0,k)<<endl;
    }
    return 0;
}


