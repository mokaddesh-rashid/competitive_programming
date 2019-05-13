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
#define mod          1000000000
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

pr rr[100010], gg[100010], ole[100010], ar[100010];

int rTM(int ap, int cp, int i)
{
    if(cp>ap) return -1;
    else return (cp-ap)/rr[i].S;
}
int gTM(int ap, int cp, int i)
{
    if(cp<ap) return -1;
    else return (ap-cp)/gg[i].S;
}

int in(int a,int b,int c,int d)
{
    if(a<=c&&c<=b) return 1;
    if(a<=d&&d<=b) return 1;
    if(c<=a&&a<=d) return 1;
    if(c<=b&&b<=d) return 1;

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,r,g,a=0,b,c=-1,d,e,f,mx,mn,z;
    cin>>r>>g>>n;
    FOR(i,0,r-1) cin>>rr[i].F;
    FOR(i,0,r-1) cin>>rr[i].S;
    FOR(i,0,g-1) cin>>gg[i].F;
    FOR(i,0,g-1) cin>>gg[i].S;
    a=0;
    FOR(i,0,n-1)
    {
        cin>>x;
        ar[i].F=a; ar[i].S=x;
        a=x;
    }
    ar[n].F=a; ar[n].S=mod;

    FOR(i,0,n)
    {
        x=ar[i].F; y=ar[i].S;
        if(rr[0].S==0)
        {
            if(x<=rr[0].F&&rr[0].F<=y) c=i;
        }
        else if(gg[0].S==0)
        {
            if(x<=gg[0].F&&gg[0].F<=y) c=i;
        }
        else
        {
            a=rTM(x,rr[0].F,0); b=rTM(y,rr[0].F,0);
            if(a==-1&&b!=-1) a=0;
            d=gTM(x,gg[0].F,0); e=gTM(y,gg[0].F,0);
            if(d!=-1&&e==-1) e=0;
            if(a!=-1&&b!=-1&&d!=-1&&e!=-1) z=in(a,b,e,d);
            if(z==1) c=i;
        }
        if(c!=-1) break;
    }
    cout<<a<<' '<<b<<' '<<e<<' '<<d<<NL;
    if(c!=-1)
    {
        FOR(i,0,r-1)
        {
            a=rTM(x,rr[c].F,0); b=rTM(y,rr[c].F,0);
            if(a==-1&&b!=-1) a=0;
            if(i==0) mn=a, mx=b;
            else mn=max(mn,a); mx=min(b,mx);
            cout<<a<<' '<<b<<NL;
        }
        FOR(i,0,g-1)
        {
            d=gTM(x,gg[c].F,0); e=gTM(y,gg[c].F,0);
            if(d!=-1&&e==-1) e=0;
            mn=max(mn,e); mx=min(d,mx);
            cout<<c<<' '<<d<<NL;
        }
    }
    cout<<c<<NL;
    if(c==-1||mx<mn) cout<<-1<<NL;
    else cout<<c+1<<NL;
    return 0;
}


