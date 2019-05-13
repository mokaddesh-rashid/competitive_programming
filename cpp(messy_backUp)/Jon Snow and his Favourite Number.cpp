#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
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

int cnt[10001], cng[10001], prev[3][100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, k, mx=0, mn, a, b, c=0, l=0;
    cin>>n>>k>>x;
    FOR(i,0,n-1) cin>>a, cnt[a]++, mx=max(mx,a);
    FOR(t,1,k)
    {
        if(l==0)
        {
            FOR(i,0,mx) prev[c][i]=cnt[i];
            a=0;
            FOR(i,0,mx)
            {
                FOR(j,0,cnt[i]-1)
                {
                   if(a%2==0) b=i^x;
                   else b=i;
                   cng[b]++;
                   mx=max(mx,b);
                   a++;
                }
            }
            a=0;
            FOR(i,0,mx)
            {
                cnt[i]=cng[i];
                cng[i]=0;
            }
            if(c==2)
            {
                a=0;
                FOR(i,0,mx) if(prev[0][i]!=prev[2][i])a=1;
                if(a==0) l=1;
                c=0;
            }
            c++;
            c%=3;
        }
        else
        {
            c++;
            c%=2;
        }
    }
    if(l==1)
        FOR(i,0,mx) cnt[i]=prev[c][i];
    a=b=-1;
    FOR(i,0,mx)
    {
        if(cnt[i]!=0&&a==-1) a=i;
        if(cnt[i]!=0) b=i;
    }
    cout<<b<<' '<<a<<NL;
    return 0;
}
