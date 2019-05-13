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
#define sz 110
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,m, dp[sz][sz],row,col;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

void up()
{
    FOR(l,0,100)
    {
        FOR(i,0,n-1)
        {

            FOR(j,0,m-1)
            {
                int a=0, x, y;
                FOR(k,0,3)
                {
                    x=i+fx[k]; y=j+fy[k];
                    if(valid(x,y)&&dp[x][y]==1) a++;
                }
                if(a>=2) dp[i][j]=1;
            }
        }
    }
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
        mem(dp,0);
        int i,j,a,b,x,y;
        cin>>n>>m; row=n; col=m;
        cout<<max(n,m)<<NL;

        if(min(n,m)==1)
        {
            if(n==1) FOR(i,0,max(n,m)-1) cout<<0<<' '<<i<<NL;
            else if(m==1) FOR(i,0,max(n,m)-1) cout<<i<<' '<<0<<NL;
        }
        else
        {
            a=b=1; x=y=0;
            FOR(i,0,max(n,m)-1)
            {
                //dp[x][y]=1;
                cout<<x<<' '<<y<<NL;
                if(x==n-1) a=-1;
                if(x==0) a=1;
                if(y==m-1) b=-1;
                if(y==0) b=1;

                x+=a;
                y+=b;
            }
//        up();
//        FOR(i,0,n-1)
//        {
//            FOR(j,0,m-1) cout<<dp[i][j]<<' ';
//            cout<<NL;
//        }
        }
    }

    return 0;
}


