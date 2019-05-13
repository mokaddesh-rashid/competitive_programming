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

int ar[10010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i, j, x=0, y, n, m, a=0, b=0, z=0;
        cin>>n>>m;
        FOR(i,0,n-1) cin>>ar[i];
        i=0;
        while(a<n)
        {
            //cout<<a<<' '<<i<<NL;
            if(ar[i]<0) z=0;
            else z+=ar[i];
            x+=ar[i];
            if(x<0&&i<n)
            {
             a=i+1;
             x=0;
            }
            else if(i-a+1>m||i==n)
            {
                x-=ar[a]; a++;
            }
            b=max(x,b); b=max(z,b);
            if(i<n)i++;
        }
        cout<<b<<NL;
    }
    return 0;
}

