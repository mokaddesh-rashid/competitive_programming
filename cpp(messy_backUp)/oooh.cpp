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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int cnt[30], tok[100010];
string str;
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,a=minn,b=maxx,c,y,z,n,m,x=0, t=0;
        cin>>n;
        FOR(i,0,n-1)
        {
            cin>>c;
            if(c>0) x+=c;
            if(c%2)
            {
              if(t==0) b=c, t=1;
              else if(c>0)b=min(b,c);
              else b=max(b,c);
              a=max(a,c);
            }
        }
        b=max(b,b*-1);
        if(x%2==0) cout<<max(a,x-b)<<NL;
        else cout<<x<<NL;
    }
    return 0;
}
