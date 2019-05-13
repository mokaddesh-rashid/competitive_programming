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
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[100010],lf[100010],rg[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,n,m,a,b,c;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    b=n;
    FOR(i,0,n-1)
    {
        a=ar[i]; lf[a]=i+1;
        rg[a]=b; b--;
    }
    cin>>m;
    a=0; b=0;
    FOR(i,0,m-1)
    {
        cin>>x;
        a+=lf[x]; b+=rg[x];
    }
    cout<<a<<' '<<b<<NL;
    return 0;
}


