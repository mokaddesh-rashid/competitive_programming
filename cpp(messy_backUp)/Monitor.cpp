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
#define MAX 510
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> pr;

struct info
{
    int x,y,t;
}ar[MAX*MAX];
int n,m,k,q;
int mp[MAX][MAX],dwn[MAX][MAX],rgt[MAX][MAX];

int down(int a,int b)
{
    if(mp[a][b]==0) return 0;
    else if(dwn[a][b]!=0) return dwn[a][b];

    return dwn[a][b]=1+down(a+1,b);
}

int right(int a,int b)
{
    if(dwn[a][b]<k) return 0;
    else if(rgt[a][b]!=0) return rgt[a][b];

    return rgt[a][b]=1+right(a,b+1);
}
int chk(int v)
{
    mem(dwn,0);mem(mp,0);mem(rgt,0);
    FOR(i,0,q-1)
       if(ar[i].t<=v) mp[ar[i].x][ar[i].y]=1;

    int a,b,c;
    FOR(i,0,q-1)
       a=down(ar[i].x,ar[i].y);
    FOR(i,0,q-1)
       a=right(ar[i].x,ar[i].y);

    FOR(l,0,q-1)
    {
        a=ar[l].x; b=ar[l].y;
        if(rgt[a][b]>=k)return 1;
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j;

    cin>>n>>m>>k>>q;
    FOR(i,0,q-1)cin>>ar[i].x>>ar[i].y>>ar[i].t;

    int st=0,en=mod,mid,c=mod,a,b;
    while(st<=en)
    {
        mid=(st+en)>>1;
        a=chk(mid);
        ///cout<<mid<<' '<<a<<NL<<NL;
        if(a==1)en=mid-1,c=min(c,mid);
        else st=mid+1;
    }

    if(c==mod)c=-1;

    cout<<c<<NL;
    return 0;
}


