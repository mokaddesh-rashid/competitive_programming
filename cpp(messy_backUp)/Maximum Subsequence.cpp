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
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL n,m,ar[20],br[20],modu,ans,lf[MAX],rg[MAX],l,r;

void F()
{
    FOR(i,1,(1<<n)-1)
    {
        LL c=0;
        FOR(j,0,n-1)
            if(i&(1<<j)) c+=ar[j], c%=modu;
        lf[l++]=c; ans=max(ans,c);
    }
}

void S()
{
    FOR(i,1,(1<<m)-1)
    {
        LL c=0;
        FOR(j,0,m-1)
            if(i&(1<<j)) c+=br[j], c%=modu;
        rg[r++]=c; ans=max(ans,c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,a;

    cin>>x>>modu; n=x/2;
    FOR(i,0,x-1)
    {
       if(i<n) cin>>ar[i];
       else  cin>>br[m++];
    }
//    cout<<n<<' '<<m<<NL;
    F(); S();

    sort(lf,lf+l);
    sort(rg,rg+r);

    FOR(i,0,l-1)
    {
        x=modu-lf[i];
        a=lower_bound(rg,rg+r,x)-rg;
        a--;
        if(a>=0)ans=max(ans,(lf[i]+rg[a])%modu);
    }

    cout<<ans<<NL;

    return 0;
}


