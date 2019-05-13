#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
#define MAX 33
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL t1,t2,n,m, val[MAX],dp[310][310][30];
pr mat[MAX][MAX];

LL rec(LL x,LL y,LL p)
{
    ///cout<<x<<' '<<y<<' '<<p<<NL;
    if(x<0||y<0) return maxx;
    if(p==n) return 0;

    if(dp[x][y][p]!=-1) return dp[x][y][p];

    LL temp=maxx, a, b, c;
    FOR(i,0,val[p])
    {
        ///if(i>x||val[p]-i>y) break;
        a=mat[p][i].F+mat[p][val[p]-i].S;
        temp=min(temp, a+rec( x-i, y-(val[p]-i), p+1 ));
    }

    FOR(i,0,val[p])
    {
        ///if(i>y||val[p]-i>x) break;
        a=mat[p][i].S+mat[p][val[p]-i].F;
        temp=min(temp, a+rec( x-(val[p]-i), y-i, p+1 ));
    }
    return dp[x][y][p]=temp;
}

void prin(LL x,LL y,LL p)
{
    ///cout<<x<<' '<<y<<' '<<p<<NL;
    if(p==n) return;
    FOR(i,0,val[p])
    {
        if(i>x||val[p]-i>y) break;

        LL a;
        a=mat[p][i].F+mat[p][val[p]-i].S+rec( x-i, y-(val[p]-i), p+1 );
        if(a==dp[x][y][p])
        {
            cout<<i<<' ';
            prin( x-i,y-(val[p]-i),p+1);
            return;
        }
    }
    FOR(i,0,val[p])
    {
        if(i>y||val[p]-i>x) break;

        LL a;
        a=mat[p][i].S+mat[p][val[p]-i].F+rec( x-(val[p]-i), y-i, p+1 );
        if(a==dp[x][y][p])
        {
            cout<<i<<' ';
            prin( x-(val[p]-i), y-i, p+1);
            return;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    while(true)
    {
        mem(mat,0); mem(val,0);
        mem(dp,-1);
        LL i,j,x;

        cin>>t1>>t2;
        if(t1==0&&t2==0) break;
        cin>>n;
        FOR(i,0,n-1)
        {
            cin>>val[i];
            FOR(j,1,val[i]) cin>>mat[i][j].F;
            FOR(j,1,val[i]) cin>>mat[i][j].S;
        }

        cout<<rec(t1,t2,0)<<NL;
        prin(t1,t2,0);
        cout<<NL<<NL;
    }
    return 0;
}


