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

LL ar[sz], mat[32][sz];
vector<LL>con[sz];

void merge_it(LL arr[],LL st,LL mid,LL en)
{
    LL n,n2;

    n=(mid-st)+1; n2=en-mid;

    LL f_half[n+1],s_half[n2+1],i,j,k;

    for(i=0;i<n;i++) f_half[i]=arr[st+i];
    for(i=0;i<n2;i++) s_half[i]=arr[mid+1+i];

    i=j=0; k=st;
    while(i<n&&j<n2)
    {
        if(f_half[i]<s_half[j]) arr[k]=f_half[i],i++,k++;
        else arr[k]=s_half[j],j++,k++;

    }

    while(i<n)
    {
        arr[k]=f_half[i];
        i++; k++;
    }

    while(j<n2)
    {
        arr[k]=s_half[j];
        j++; k++;
    }

}

void divide(LL arr[],LL st,LL en,LL p)
{
    LL mid;

    if(st<en)
    {
        mid=(st+en)>>1;
        divide(arr,st,mid,p+1);
        divide(arr,mid+1,en,p+1);

        merge_it(arr,st,mid,en);
        FOR(i,st,en) mat[p][i]=arr[i];
    }
    else mat[p][st]=arr[st];
}

LL query(LL st,LL en,LL l,LL r,LL p,LL v)
{
    if(en<l||st>r) return 0;
    else if(l<=st&&en<=r)
    {
        LL t=lower_bound(mat[p]+st,mat[p]+en+1,v)-mat[p];
        return en+1-t;
    }

    LL mid=(st+en)>>1;
    return query(st,mid,l,r,p+1,v)+query(mid+1,en,l,r,p+1,v);
}

pr in[MAX];
LL bm(LL n, LL p)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % mod;

    LL ret = bm(n, p/2);
    ret = (ret * ret) % mod;
    if(p % 2) ret = (ret * n) % mod;
    return ret%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL n,m,i,j,a,b,c,x,y,z,l,r,v,k;
    LL cnt=0;

    cin>>n;
    FOR(i,0,n-1) cin>>in[i].F>>in[i].S;
    sort(in,in+n);
    FOR(i,0,n-1) ar[i]=in[i].S;
    divide(ar,0,n-1,0);

    FOR(i,0,n-1)
    {
        v=in[i].S;
        x=query(0,n-1,i+1,n-1,0,v);
        y=(n-i)-1;
        y=y-x;
        //y=bm(2,y);
        cnt+=y;
        cnt%=mod;

        ///cout<<l-1<<' '<<r-1<<' '<<x<<NL;
    }
    cout<<cnt<<NL;
}


