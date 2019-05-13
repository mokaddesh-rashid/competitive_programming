#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

LL x, y, xx, yy;
LL area(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3)
{
   // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<endl;
    return (x1*(y2-y3))-(x2*(y1-y3))+(x3*(y1-y2));
}

LL valid_tri(LL a, LL b, LL c, LL d)
{
    LL l, ck=0, ll, k, kk;

    l=area(x,y,a,b,xx,yy);
    ll=area(x,y,c,d,xx,yy);
    //cout<<l<<' '<<ll<<endl;
    if(l==0||ll==0) return 1;
    if(l<0&&ll>0) return 1;
    if(l>0&&ll<0) return 1;
    return ck;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    LL tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        LL i, j, n, m, a, b, c, d, cnt=0;
        cin>>x>>y>>xx>>yy>>a>>b>>c>>d;
        if(a>c)swap(a,c);
        if(b<d)swap(b,d);
        //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
        cnt=max(cnt,valid_tri(a,b,a,d));
        cnt=max(cnt,valid_tri(a,b,c,b));
        cnt=max(cnt,valid_tri(c,d,a,d));
        cnt=max(cnt,valid_tri(c,d,c,b));
        //cout<<valid_tri(c,d,c,b)<<endl;
        if(cnt==1)cout<<'T'<<endl;
        else cout<<'F'<<endl;
    }
    return 0;
}
