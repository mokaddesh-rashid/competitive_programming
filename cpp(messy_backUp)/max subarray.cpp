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
typedef pair<LL,LL> pr;

set<pr> ms;
set<pr>::iterator it;
LL ar[100010],sm[100010],ooh[100010],ole[100010],pos[100010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,x,y,n,m;
        LL c=0,a,b,d=0;
        cin>>n>>m;
        m=min(m,n);
        FOR(i,0,n-1) cin>>ar[i], c+=ar[i], sm[i]=c;
        x=y=a=b=0;
        FOR(i,0,n-1)
        {
            while(x<y&&sm[i]<ooh[y-1])
            {
                y--;
            }
            ooh[y]=sm[i]; pos[y]=i;y++;
            if(i>=m&&sm[i-m]==ooh[x]) x++;
            ole[i]=pos[x];
        }
        a=0;
        FOR(i,0,m-1)
        {
           a+=ar[i]; a=max(a,(LL)0);
           d=max(d,a);
        }
        FOR(i,m,n-1)
        {
            a=sm[i]-sm[i-m]; d=max(d,a);
            a=sm[i]-sm[ole[i]]; d=max(d,a);
            //cout<<i<<' '<<ole[i]<<NL;
        }
        cout<<"Case "<<tt<<": "<<d<<NL;
    }
    return 0;
}


