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
#define sz 2010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL  n, k, p, ar[sz], br[sz];

LL rec(LL x)
{
    int c=0,j,i;
    i=j=0;
    while(i<n)
    {
        if(j==k) break;
        if(abs(ar[i]-br[j])+abs(br[j]-p)<=x)
        {
            i++; c++;
        }
        j++;
    }
    if(c==n) return 1;
    else return 0;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,st,en,mid;

    cin>>n>>k>>p;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,k-1) cin>>br[i];
    sort(ar,ar+n); sort(br,br+k);

    st=0; en=maxx;
    while(st<=en)
    {
        mid=(st+en)>>1;
        //cout<<mid<<' '<<rec(mid)<<NL;
        if(rec(mid)) en=mid-1;
        else st=mid+1;
    }
    cout<<st<<NL;
    return 0;
}



