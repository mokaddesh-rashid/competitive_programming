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
#define MAX 100010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX],lft[MAX],rgt[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,d,k;

    cin>>n>>k;
    FOR(i,0,n-1)cin>>ar[i];
    FOR(i,0,n-1)
    {
        if(i==0)c=a=ar[i];
        else a=min(ar[i],a);
        lft[i]=a;
        c=max(ar[i],c);
    }
    REV(i,n-1,0)
    {
        if(i==n-1)a=ar[i];
        else a=min(ar[i],a);
        rgt[i]=a;
    }
    if(k==1||n==1)cout<<lft[n-1]<<NL;
    else if(k>2)cout<<c<<NL;
    else if(k==2)
    {
        FOR(i,0,n-2)
        {
            if(i==0)d=max(lft[i],rgt[i+1]);
            else d=max(d,max(lft[i],rgt[i+1]));
        }
        cout<<d<<NL;
    }

    return 0;
}


