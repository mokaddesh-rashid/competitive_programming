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
#define sz 1010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col)&& str[nx][ny]!='*' )
typedef pair<int,int> pr;

string str[sz];
int vis[sz][sz][5],n,m,sx,sy,tx,ty,row,col;
pr nxt[sz*sz*5];
int p,s,l=0,k;

int rec(int x,int y,int a,int b,int c)
{
    ///cout<<x<<' '<<y<<NL;
    if(str[x][y]=='T') l=1,k=1;
    vis[x][y][c]=1;
    int xx=x+a, yy=y+b;

    if(valid(xx,yy)&&vis[xx][yy][c]==0)
    {
       nxt[p].F=xx, nxt[p].S=yy, p++;
       rec(xx,yy,a,b,c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b;

    cin>>n>>m; row=n; col=m;
    FOR(i,0,n-1) cin>>str[i];

    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        {
           if(str[i][j]=='S') sx=i, sy=j;
           if(str[i][j]=='T') tx=i, ty=j;
        }
    }

    p=0;
    rec(sx,sy,1,0,1); rec(sx,sy,-1,0,2);
    rec(sx,sy,0,1,3); rec(sx,sy,0,-1,4);

    a=s; b=p; s=p;
    FOR(i,a,b-1)
    {
      sx=nxt[i].F; sy=nxt[i].S;
      rec(sx,sy,1,0,1); rec(sx,sy,-1,0,2);
      rec(sx,sy,0,1,3); rec(sx,sy,0,-1,4);
    }

    a=s; b=p;
    FOR(i,a,b-1)
    {
      sx=nxt[i].F; sy=nxt[i].S;
      rec(sx,sy,1,0,1); rec(sx,sy,-1,0,2);
      rec(sx,sy,0,1,3); rec(sx,sy,0,-1,4);
    }

    if(l==1) cout<<"YES";
    else cout<<"NO"<<NL;
    return 0;
}
