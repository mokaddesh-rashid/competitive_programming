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
#define MAX 60
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> pr;

int ar[MAX][MAX], n, m;

int up(int x,int y,int v)
{
    if(!valid(x,y)) return 0;
    if(ar[x][y]==v) return 1+up(x,y+1,v);
    else return up(x,y+1,v);
}

int down(int x,int y,int v)
{
    if(!valid(x,y)) return 0;
    if(ar[x][y]==v) return 1+down(x+1,y,v);
    else return down(x+1,y,v);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,c=0,d;
    LL x,y,z=0;

    cin>>n>>m;
    FOR(i,0,n-1)
    FOR(j,0,m-1)cin>>ar[i][j];

    FOR(i,0,n-1)
    {
            c=up(i,0,ar[i][0]);
            d=m-c;
            x=(LL)1<<c; x--;
            y=(LL)1<<d; y--;
            ///cout<<i<<' '<<' '<<c<<' '<<x<<NL;
            ///cout<<d<<' '<<y<<NL;
            z+=(x+y);
    }

    FOR(i,0,m-1)
    {
            c=down(0,i,ar[0][i]);
            d=n-c;
            x=(LL)1<<c; x--;
            y=(LL)1<<d; y--;
            ///cout<<c<<' '<<x<<NL;
            ///cout<<d<<' '<<y<<NL;
            z+=(x+y);
    }
    cout<<z-(n*m)<<NL;
    return 0;
}


