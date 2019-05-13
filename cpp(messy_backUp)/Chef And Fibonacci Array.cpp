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
#define mod1          1000007
#define mod2          100000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MX 2510
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

set<pr>ms;
set<pr>::iterator it;
int cnt[MX];

int chk(int ar[],int r)
{
    LL c=0, d=0, a, b, x=1, y=1, z=0;

    FOR(i,0,r)
    {
        a=(ar[i]+1)*x;   b=(ar[i]+1)*y;
        c+=a;            d+=b;
        x*=111;          y*=111;
        c%=mod1;         d%=mod2;
        x%=mod1;         y%=mod2;
    }

    if(ms.find(MP(c,d))!=ms.end()) z=1;
    //FOR(i,0,r) cout<<ar[i]<<' ';
    //cout<<NL<<z<<NL;
    ms.insert(MP(c,d));
    return z;
}


void rec(int ar[],int r)
{
    //FOR(i,0,r) cout<<ar[i]<<' ';
    ///cout<<NL;
    int a,b,c=r;
    FOR(i,0,r-1)
    {
        if(ar[i]>0&&ar[i+1]>0&&i+2<=r)
        {
            cnt[i]++; cnt[i+1]++; cnt[i+2]++;
            ar[i]--; ar[i+1]--; ar[i+2]++;
            if(chk(ar,r)==0) rec(ar,r);
            ar[i]++; ar[i+1]++; ar[i+2]--;
        }
        else if(ar[i]>0&&ar[i+1]>0)
        {
            cnt[i]++; cnt[i+1]++; cnt[i+2]++;
            ar[i]--; ar[i+1]--; ar[i+2]++;
            if(chk(ar,r+1)==0)  rec(ar,r+1);
            ar[i]++; ar[i+1]++; ar[i+2]--;
        }
    }
}

int ar[MX];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int i,j,n,m;
        mem(ar,0); mem(cnt,0);
        cin>>n;
        FOR(i,0,n-1) cin>>ar[i];
        rec(ar,n-1);
        cout<<ms.size()+1<<NL<<NL;
        FOR(i,0,20) cout<<cnt[i]<<' ';
        cout<<NL;
        while(!ms.empty())
        {
            ms.erase(ms.begin());
        }
    }
    return 0;
}

