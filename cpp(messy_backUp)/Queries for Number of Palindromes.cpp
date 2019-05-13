#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define ss(n)       scanf(" %s", n)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
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
#define MAX 5010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

char str[MAX];
int dp[MAX][MAX];

int rec(int x,int y)
{
    if(x==y) return 1;
    if(x>y) return 0;
    if(dp[x][y]!=-1) return dp[x][y];

    if(str[x]==str[y]) dp[x][y]=2+rec(x+1,y-1);
    else dp[x][y]=rec(x+1,y-1);
    return dp[x][y];
}

int ans[MAX][MAX];

int shit(int x,int y)
{
    if(x>y) return 0;
    if(ans[x][y]!=-1)return ans[x][y];

    int temp=0,a=0;
    if(rec(x,y)==abs(x-y)+1)a=1;

    temp=a+shit(x+1,y)+shit(x,y-1)-shit(x+1,y-1);
    return ans[x][y]=temp;
}

int main()
{
    //ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(dp,-1);mem(ans,-1);///mem(vis,-1);t=1;
    int i,j,n,m,a,b,c;

    ss(str);n=strlen(str);//.size();

    sf(m);//cin>>m;
    FOR(i,0,m-1)
    {
        sff(a,b);//cin>>a>>b;
        pf("%d\n",shit(a-1,b-1));
        //cout<<shit(a-1,b-1)<<NL;
//        t++;
    }

    return 0;
}


