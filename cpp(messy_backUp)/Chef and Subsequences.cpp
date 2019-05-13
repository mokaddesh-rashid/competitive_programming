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

LL fs[100010], ss[100010], f, s, ar[20], br[20],n,m,k;

void rec(LL p,LL v)
{
    if(p==n)
    {
        if(v>0&&v<=k) fs[f]=v, f++;
        return;
    }
    if(v>k) return;

    LL a,b,c,x,y;

    if(v==0) a=ar[p];
    else a=ar[p]*v;

    rec(p+1,v);
    if(a%ar[p]==0) rec(p+1,a);

}

void rec2(LL p,LL v)
{
    if(p==m)
    {

        if(v>0&&v<=k) ss[s]=v, s++;
        return;
    }
    if(v>k) return;

    LL a,b,c,x,y;

    if(v==0) b=br[p];
    else b=br[p]*v;

    if(b%br[p]==0) rec2(p+1,b);
    rec2(p+1,v);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,a,b,c;

    cin>>a>>k;
    n=a/2;
    m=a-n;

    FOR(i,0,n-1)
    {
        cin>>a;
        if(a<=k)ar[i]=a;
        else i--,n--;
    }
    FOR(i,0,m-1)
    {
        cin>>a;
        if(a<=k)br[i]=a;
        else i--,m--;
    }
    //cout<<n<<' '<<m<<NL;
    rec(0,0);
    rec2(0,0);

    c=f+s;
    sort(ss,ss+s);
    //cout<<f<<' '<<s<<NL;
    //FOR(i,0,s-1) cout<< br[i]<<' ';
    //cout<<NL;
    FOR(i,0,f-1)
    {
        y=k/fs[i];
        a=upper_bound(ss,ss+s,y)-ss;
        c+=a;
    }
    cout<<c<<NL;
    return 0;
}
