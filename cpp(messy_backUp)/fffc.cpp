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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL lf[sz], rg[sz], ar[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,x,y,n,m,a,b,c=0,d=maxx,z;

        cin>>n;
        FOR(i,0,n-1) cin>>ar[i], c+=ar[i];

        x=0;
        FOR(i,0,n-1)
        {
            x=min(ar[i],x+1);
            lf[i]=x;
        }

        x=0;
        REV(i,n-1,0)
        {
            x=min(ar[i],x+1);
            rg[i]=x;
        }

        FOR(i,0,n-1)
        {
            x=min(lf[i],rg[i]);
            y=x*(x+1); y/=2;
            z=x*(x-1); z/=2;
            x=y+z;
            d=min(d,c-x);
        }

        cout<<d<<NL;
    }
    return 0;
}


