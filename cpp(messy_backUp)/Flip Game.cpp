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
#define MAX 110
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> pr;

int ar[MAX][MAX],n,m;

int rec(int i,int j)
{
    ///cout<<i<<' '<<j<<NL;
    if(!valid(i,j))return 0;
    else return ar[i][j]+rec(i+1,j);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,c;
    LL x,y,z=0,a,b;

    cin>>n>>m; c=m-1;
    FOR(i,0,n-1)
    FOR(j,0,m-1)cin>>ar[i][j];

    FOR(i,0,n-1)
        if(ar[i][0]==0)
            FOR(j,0,m-1) ar[i][j]++,ar[i][j]%=2;

    FOR(i,0,m-1)
    {
       a=max(rec(0,i),n-rec(0,i));
       cout<<i<<' '<<a<<' '<<c<<NL;
       x=((LL)1<<c)*a;
       cout<<x<<NL;
       z+=x;
       c--;
    }

    cout<<z<<NL;
    return 0;
}


