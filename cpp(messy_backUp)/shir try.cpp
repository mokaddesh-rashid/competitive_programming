#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
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

map<LL,LL>ms;
map<LL,LL>::iterator it;
LL br[64*sz], va[64*sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,q,x,y,z,n,m,a,b,c;
    pr ck;

    sff(n,q);//cin>>n>>q;
    FOR(i,0,n-1)
    {
        sf(a);///cin>>a;
        while(a>0)
        {
            ms[a]++;
            a/=2;
        }
    }

    m=0; c=0;
    for(it=ms.begin();it!=ms.end();it++)
    {
        x=it->F; y=it->S; c+=y;
        br[m]=x; va[m]=c; m++;
    }


    FOR(i,0,q-1)
    {
        cin>>a;
        a=c-a+1;
        a=lower_bound(va,va+m,a)-va;
        cout<<br[a]<<NL;
    }
    return 0;
}
