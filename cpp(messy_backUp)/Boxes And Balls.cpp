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
#define LL            long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX];
LL val,c,sum[MAX],d;

void rec(int st,int en)
{

    if(st>=en)return;

    int x,y,z;
    LL vv=0;

    val=sum[en];
    if(st!=0)val-=sum[st-1],vv=sum[st-1];
    c=val/3;
    ///if(en-st<=2)return val;


    x=st+1;

    vv=sum[x];
    y=lower_bound(sum+x+1,sum+en+1,vv+c)-sum;
    y=min(en,y);

    if(x==y) x=(st+x)/2;


    x=max(st,x);
    y=max(x+1,y);
    y=min(y,en-1);

    if(x-1>=st&&x==y) x--;

    d+=val;


    rec(st,max(st,x));
    rec(max(st,x)+1,max(max(st,x)+1,y));
    rec(max(max(st,x)+1,y)+1,en);


}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    sort(ar,ar+n);
    FOR(i,0,n-1) c+=ar[i],sum[i]=c;

    rec(0,n-1);
    cout<<d<<NL;
    return 0;
}


