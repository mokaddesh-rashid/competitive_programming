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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
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
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,ar[MAX],k;

int chk(int v)
{
    int c=0, p=0;
    while(p<n)
    {
        p=upper_bound(ar,ar+n,ar[p]+v)-ar;
        c++;
    }
    if(c<k)return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m=mod,st,en,mid;

    cin>>n>>k;
    FOR(i,0,n-1)cin>>ar[i];
    sort(ar,ar+n);

    st=0;
    en=mod;

    while(st<=en)
    {
        mid=(st+en)/2;
        if(chk(mid)) en=mid-1,m=min(mid,m);
        else st=mid+1;
    }
    cout<<m<<NL;

    return 0;
}



