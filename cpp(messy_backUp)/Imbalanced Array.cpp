#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL ar[sz], nmi[sz], nma[sz], tp, val[sz],n;
pr stk[sz];

LL ret_min()
{
    LL a,b,c;
    FOR(i,0,sz-1) val[i]=1;
    tp=-1;
    FOR(i,0,n-1)
    {
        while(tp>=0&&ar[i]<stk[tp].F)
        {
            nma[stk[tp].S]=i;
            tp--;
        }
        stk[++tp].F=ar[i];
        stk[tp].S=i;
    }

    while(tp>=0)
    {
        nma[stk[tp].S]=n;
        tp--;
    }

    c=0;
    FOR(i,0,n-1)
    {
        a=ar[i]*(nma[i]-i)*val[i];
        val[nma[i]]+=val[i];
        c+=a;
    }
    return c;
}

LL ret_max()
{
    LL a,b,c;
    FOR(i,0,sz-1) val[i]=1;
    tp=-1;
    FOR(i,0,n-1)
    {
        while(tp>=0&&ar[i]>stk[tp].F)
        {
            nma[stk[tp].S]=i;
            tp--;
        }
        stk[++tp].F=ar[i];
        stk[tp].S=i;
    }

    while(tp>=0)
    {
        nma[stk[tp].S]=n;
        tp--;
    }

    c=0;
    FOR(i,0,n-1)
    {
        a=ar[i]*(nma[i]-i)*val[i];
        val[nma[i]]+=val[i];
        c+=a;
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x=0,y=0,m,a,b,c=0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    c+=ret_max();
    c-=ret_min();
    cout<<c<<NL;
    return 0;
}


