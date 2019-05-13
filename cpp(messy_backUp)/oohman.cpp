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

int cnt, vis[2][sz],row,col,n;
string str[3];

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

int solve(string ok,string no)
{
    int x,y,a;

    x=y=1000;
    mem(vis,0);
    str[0]=ok; str[1]=no;
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
    a=rec(x,y);
    ///cout<<str[0]<<NL<<str[1]<<NL;
    ///cout<<a<<NL;
    return a;
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
        int i,j,x,y=1000,m,a=0,b,c=0;
        string rev, reva, ori, oria;
        rev=reva="";

        cnt=0;
        cin>>n; row=2; col=n;
        FOR(i,0,1) cin>>str[i];

        ori=str[0]; oria=str[1];
        REV(i,n-1,0)
        {
            if(str[0][i]=='#')cnt++;
            if(str[1][i]=='#')cnt++;
            rev+=str[0][i];
            reva+=str[1][i];
        }
        a=max(a,solve(ori,oria));
        a=max(a,solve(oria,ori));
        a=max(a,solve(reva,rev));
        a=max(a,solve(rev,reva));
        ///cout<<cnt<<NL;
        if(a==cnt) cout<<"yes"<<NL;
        else cout<<"no"<<NL;
    }
    return 0;
}

