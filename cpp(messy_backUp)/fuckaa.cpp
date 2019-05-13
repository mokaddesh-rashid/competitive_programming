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
#define mod          10000007
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
LL val[sz], po[sz], rval[sz], rpo[sz];

LL bm(LL n, LL p)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % mod;

    LL ret = bm(n, p/2);
    ret = (ret * ret) % mod;
    if(p % 2) ret = (ret * n) % mod;
    return ret%mod;
}

LL modinv( LL n )
{
    return bm( n, mod-2);
}


int cnt[sz];

LL has_val(int x,int y)
{
    LL a,b,c;
    if(x==0) return val[y];
    else
    {
        a=(mod+val[y])-val[x-1]; a%=mod;
        b=po[x];
        ///cout<<a<<' '<<b<<NL;
        a*=b; a%=mod;
        ///cout<<a<<NL;
    }
    return a;
}
LL rhas_val(int x,int y)
{
    LL a,b,c;

        a=(mod+rval[x])-rval[y+1]; a%=mod;
        b=rpo[y];
        ///cout<<a<<' '<<b<<NL;
        a*=b; a%=mod;
        ///cout<<a<<NL;

    return a;
}

int dp[sz][sz];
int rec(int x,int y)
{
    if(x>y) return 0;
    if(x==y) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    int a,b,c,d=((y-x)+1)/2;

    a=x+d-1; b=y-d+1;
    if(has_val(x,a)==has_val(b,y) && (has_val(x,y)==rhas_val(x,y))) return dp[x][y]=1+min(rec(x,a),rec(b,y));
    else if(has_val(x,y)==rhas_val(x,y))return dp[x][y]=1;
    else return dp[x][y]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    LL i,j,n,m,a,b,c,x,y,z,v,d;

    cin>>str;

    v=1; c=0; n=str.size();
    FOR(i,0,n-1)
    {
       a=str[i]-'a'; a++;
       x=a*v;
       c+=x; c%=mod;
       val[i]=c; po[i]=modinv(v);
       v*=29; v%=mod;
    }

    v=1; c=0; n=str.size();
    REV(i,n-1,0)
    {
       a=str[i]-'a'; a++;
       x=a*v;
       c+=x; c%=mod;
       rval[i]=c; rpo[i]=modinv(v);
       v*=29; v%=mod;
    }

    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            x=rec(i,j);
            ///cout<<i<<' '<<j<<' '<<x<<NL;
            cnt[x]++;
        }
    }
    int ans[sz];
    c=0;
    REV(i,n,1)
    {
        c+=cnt[i];
        ans[i]=c;
    }
    FOR(i,1,n) cout<<ans[i]<<' ';

    return 0;
}

