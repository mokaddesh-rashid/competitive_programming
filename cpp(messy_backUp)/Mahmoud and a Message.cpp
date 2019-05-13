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

string str;
int ar[1000], n, mx;
int dp[1001][1001][27];
int rec(int x, int y, int z)
{
    //cout<<x<<' '<<y<<endl;
    if(x==n) return 1;
    mx=max(y,mx);
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    int a, b, c, temp;
    a=str[x]-'a';
    temp=rec(x+1,1,a);

    if(ar[a]<ar[z]) z=a;
    if(y+1<=ar[z]) temp+=rec(x+1,y+1,z);

    return dp[x][y][z]=(temp%mod);
}

int rec1(int x, int y, int z)
{
    //cout<<x<<' '<<y<<endl;
    mx=max(y,mx);
    if(x==n) return 0;
    int a, b, c, temp;

    a=str[x]-'a';
    if(ar[a]<ar[z]) z=a;
    if(y+1<=ar[z]) temp=rec1(x+1,y+1,z);
    else temp=1+rec1(x+1,1,a);

    return temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1); mx=0;
    int i, j, x, y, m;
    cin>>n;
    cin>>str;
    FOR(i,0,25) cin>>ar[i];
    x=rec(0,0,26);
    y=rec1(0,0,26);
    cout<<x<<endl;
    cout<<mx<<endl;
    cout<<y<<endl;
    return 0;
}


