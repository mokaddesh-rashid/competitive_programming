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


int ar[MAX],n;
int rec(int x,int y,int z)
{
    //cout<<x<<' '<<y<<NL;
    if(x==1)return 0;

    int a=__gcd(x,y);
    int b=__gcd(x,z);

    if(min(a,b)==x)return mod;
    return 1+rec(min(a,b),y,z);
}

int chk(int p)
{
    int cnt=0;
    FOR(i,0,n-1)
        if(i!=p&&ar[i]>1)cnt++;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m,c=mod,a,b,cnt=0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
//
    FOR(i,0,n-1)
    {
        a=b=ar[i];
        if(i!=n-1) a=ar[i+1];
        if(i!=0) b=ar[i-1];
        int d=rec(ar[i],a,b)+chk(i);
        c=min(c,d);
    }
    if(c==mod) c=-1;
    cout<<c<<NL;

    return 0;
}
/*
5
2 2 3 4 6
*/

