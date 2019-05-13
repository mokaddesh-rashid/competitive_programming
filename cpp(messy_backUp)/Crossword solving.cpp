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
#define sz 1010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,m,dp[sz][sz][2];
string s,t;

int rec(int x,int y,int z)
{
    cout<<x<<' '<<y<<' '<<z<<NL;
    if(x==n) return 0;
    else if(y==m) return mod;
    if(dp[x][y][z]!=-1) return dp[x][y][z];

    int temp=mod;
    if(z==0)
    {
        if(s[x]==t[x]) temp=min(temp,rec(x+1,y+1,1));
        temp=min(temp,1+rec(x+1,y,1));
        temp=min(temp,rec(x,y+1,0));
    }
    else
    {
        if(s[x]!=t[x]) temp=min(temp,1+rec(x+1,y+1,1));
        else temp=min(temp,rec(x+1,y+1,1));
    }

    return dp[x][y][z]=temp;
}

void prin(int x,int y,int z)
{
    if(x==n) return;
    else if(y==m) return;

    int temp=rec(x,y,z);

    if(z==0)
    {
        if(s[x]==t[x])
        {
            if(temp==rec(x+1,y+1,1))
            {
                prin(x+1,y+1,1);
                return;
            }
        }
        if(temp==1+rec(x+1,y,0))
        {
            cout<<x+1<<' ';
            prin(x+1,y,0);
            return;
        }
        if(temp==rec(x,y+1,0))
        {
            prin(x,y+1,0);
            return;
        }
    }
    else
    {
        if(s[x]!=t[x])
        {
            cout<<x+1<<' ';
            prin(x+1,y+1,1);
            return;
        }
        else
        {
            prin(x+1,y+1,1);
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,a,b,c;

    cin>>n>>m;
    cin>>s>>t;

    c=rec(0,0,0);
    cout<<c<<NL;
    prin(0,0,0);
    return 0;
}


