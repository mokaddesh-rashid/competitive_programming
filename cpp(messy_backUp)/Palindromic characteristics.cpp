
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
#define sz 5010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str;
int isp[sz][sz], dp[sz][sz];

int cpl(int x,int y)
{
    if(x>y) return 0;
    if(isp[x][y]!=-1) return isp[x][y];
    int temp=0,a;

        temp=max(temp,cpl(x+1,y));
        temp=max(temp,cpl(x,y-1));
        if(str[x]==str[y])
        {
            a=2;
            if(x==y) a=1;
            temp=max(temp,a+cpl(x+1,y-1));
        }

    return isp[x][y]=temp;
}

int cnt[sz];

int rec(int x,int y)
{
    ///cout<<x<<' '<<y<<' '<<cpl(x,y,0)<<' '<<abs(y-x)+1<<NL;
    if(x>y) return 0;
    if(x==y) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    int a,b,c,d=((y-x)+1)/2;

    a=x+d-1; b=y-d+1;
    if(cpl(x,y)==abs(y-x)+1) return dp[x][y]=1+min(rec(x,a),rec(b,y));
    else return dp[x][y]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(isp,-1);
    mem(dp,-1);
    int i,j,n,m,a,b;

    cin>>str;
    n=str.size();
    a=cpl(0,n-1);

    FOR(i,0,n-1)
    FOR(j,0,n-1)
    {
        a=rec(i,j);
        cnt[a]++;
    }

    int ans[sz];
    int  c=0;
    REV(i,n,1)
    {
        c+=cnt[i];
        ans[i]=c;
    }
    FOR(i,1,n) cout<<ans[i]<<' ';
    return 0;
}

