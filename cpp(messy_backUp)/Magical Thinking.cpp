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
#define sz 60
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[sz][sz][sz][sz], n, q, val[4];
string str[4];

int rec(int p,int x,int y,int z)
{
    //cout<<p<<' '<<x<<' '<<y<<' '<<z<<NL;
    ///cout<<val[0]<<' '<<val[1]<<NL;
    if(p==q&&x==val[0]&&y==val[1]) return z;
    if(p==q) return mod*-1;
    if(dp[p][x][y][z]!=-1) return dp[p][x][y][z];

    ///true
    int a,b,c;

    a=b=c=0;
    if(str[0][p]=='T') a=1;
    if(str[1][p]=='T') b=1;
    if(str[2][p]=='T') c=1;
    dp[p][x][y][z]=rec(p+1,x+a,y+b,z+c);

    ///false
    a=b=c=0;
    if(str[0][p]=='F') a=1;
    if(str[1][p]=='F') b=1;
    if(str[2][p]=='F') c=1;
    dp[p][x][y][z]=max(dp[p][x][y][z],rec(p+1,x+a,y+b,z+c));

    return dp[p][x][y][z];


}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(dp,-1);
        int i,j;

        cin>>n>>q;
        FOR(i,0,n-1)
        {
            cin>>str[i];
        }
        if(n==1) str[1]=str[0];
        cin>>str[2];
        FOR(i,0,n-1) cin>>val[i];
        if(n==1) val[1]=val[0];

        cout<<"Case #"<<tt<<": "<<rec(0,0,0,0)<<NL;
    }
    return 0;
}


