#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

pr ar[sz];
LL damn[sz], bs[sz],n,m,val[sz];


LL rec(LL v)
{
    ///cout<<v<<NL;
    LL a,b,c,x,y,z;
    a=upper_bound(bs,bs+n+1,v)-bs; a--;

    if(val[a]!=0) return val[a];

    x=(v-(ar[a].F-1))%damn[a];
    if(x==0) x=damn[a];

    return rec(x);

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,z,a,b,c=1,d,q;

    cin>>n;
    FOR(i,1,n)
    {
        cin>>a;
        if(a==1)
        {
            cin>>x;
            damn[i]=1;
            ar[i].F=c; ar[i].S=c;
            bs[i]=c; val[i]=x;
            c++;
        }
        else
        {
            cin>>x>>y;
            damn[i]=x;
            ar[i].F=c; ar[i].S=c+(x*y)-1;
            bs[i]=c;
            c+=(x*y);
        }
    }

    cin>>q;
    FOR(i,0,q-1)
    {
        cin>>a;
        cout<<rec(a)<<' ';
    }
    return 0;
}


