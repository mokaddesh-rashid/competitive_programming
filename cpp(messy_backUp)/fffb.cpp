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
#define sz 510
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col) && (vis[nx][ny]==0) && str[nx][ny]=='#' )
typedef pair<int,int> pr;

int cnt, vis[2][sz],row,col;
string str[3];
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

int rec(int x,int y)
{
    //cout<<x<<' '<<y<<NL;
    int a=0;

    vis[x][y]=1;
    if(x==0)
    {
       if(valid(x+1,y)) return 1+rec(x+1,y);
       else if(valid(x,y+1)) return 1+rec(x,y+1);
    }
    else
    {
        if(valid(x-1,y)) return 1+rec(x-1,y);
        else if(valid(x,y+1)) return 1+rec(x,y+1);
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,x,y=1000,n,m,a,b,c=0;
        string rev, reva;
        rev=reva="";

        mem(vis,0); cnt=0;
        cin>>n; row=2; col=n;
        FOR(i,0,1) cin>>str[i];

        FOR(i,0,1)
        {
            FOR(j,0,n-1)
            {
                if(str[i][j]=='#')
                {
                    if(j<y) x=i, y=j;
                    cnt++;
                }
            }
        }

        a=rec(x,y);

        mem(vis,0); x=y=1000;
        REV(i,n-1,0)
        {
            rev+=str[0][i];
            reva+=str[1][i];
        }
        str[0]=rev; str[1]=reva;
        FOR(i,0,1)
        {
            FOR(j,0,n-1)
            {
                if(str[i][j]=='#')
                {
                    if(j<y) x=i, y=j;
                }
            }
        }
        ///cout<<x<<' '<<y<<NL;
        a=max(a,rec(x,y));

        if(a==cnt) cout<<"yes"<<NL;
        else cout<<"no"<<NL;
    }
    return 0;
}
