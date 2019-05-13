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

int ar[MAX],dp[MAX][10],n;

int rec(int p,int l)
{
    if(p==n) return 1;
    if(dp[p][l]!=-1) return dp[p][l];

    int temp=mod*-1;
    if(ar[p]==0)
        FOR(i,l+1,9) temp=max(temp,1+rec(p+1,i));
    if(ar[p]==1)
        temp=max(temp,1+rec(p+1,l));
    if(ar[p]==2)
        FOR(i,0,l-1) temp=max(temp,1+rec(p+1,i));

    return dp[p][l]=temp;
}

void prin(int p,int l)
{
    if(p==n) return;

    int temp=mod*-1;
    if(ar[p]==0)
    {
        REV(i,9,l+1)
        {
            if(1+rec(p+1,i)==rec(p,l))
            {
                cout<<i;
                return prin(p+1,i);
            }
        }
    }
    else if(ar[p]==1)
    {
        cout<<l;
        return prin(p+1,l);
    }
    else if(ar[p]==2)
    {
        REV(i,l-1,0)
        {
            if(1+rec(p+1,i)==rec(p,l))
            {
                cout<<i;
                return prin(p+1,i);
            }
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m,x=0;

    cin>>n;
    FOR(i,1,n-1) cin>>ar[i], ar[i]++;
    REV(i,9,1)
    {
        x=rec(1,i);
        if(x==n)
        {
            cout<<i;
            prin(1,i);
            return 0;
        }
    }

    cout<<-1<<NL;
    return 0;
}


