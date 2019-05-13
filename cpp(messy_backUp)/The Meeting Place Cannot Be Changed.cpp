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
#define mod          1000000000
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

double br[100010], ar[100010];
int n;

double chk(double ooh)
{
    double a, b, c=0, d;
    int x, y;
    FOR(i,0,n-1)
    {
        a=abs(ooh-ar[i]); a=a*br[i];
        c=max(c,a);
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, m;
    double a,b,c=mod,st,en,mi,mj;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,n-1)
    {
        cin>>a; b=1/a;
        br[i]=b;
    }
    st=0; en=mod;
    FOR(i,1,100)
    {
        mi=(en-st)/3; mi+=st; mj=(mi+en)/2;
        a=chk(mi); b=chk(mj);
        if(a<b) en=mj;
        else st=mi;
        c=min(c,a); c=min(c,b);
        //cout<<mi<<' '<<mj<<' '<<st<<' '<<en<<NL;
    }
    cout<<fixed;
    cout<<setprecision(8)<<c<<NL;
    return 0;
}


