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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[sz];
int dp[sz][2], pa[sz];

int rec(int p,int v)
{
    int temp;
    if(dp[p][v]!=-1) return dp[p][v];
    if(v==0)
    {
        int t=1;
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(pa[p]!=x)
            {
                pa[x]=p;
                t+=rec(x,1);
            }
        }
        temp=t;
    }
    else
    {
        int t=0;
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(pa[p]!=x)
            {
                pa[x]=p;
                t+=rec(x,0);
            }
        }

        int s=1;
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(pa[p]!=x)
            {
                pa[x]=p;
                s+=rec(x,1);
            }
        }
        temp=min(t,s);
    }
    return dp[p][v]=temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,n,m,a,b,x,y,z;

    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b);
        mat[b].PB(a);
    }

    FOR(i,1,n) cout<<rec(i,0)<<NL;
    return 0;
}


