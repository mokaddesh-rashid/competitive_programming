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
#define sz 50
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n, dp[sz][sz], ar[sz], prin[sz];

int rec(int x,int y)
{
    if(x==0) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    if(y==1) dp[x][y]=rec(x-1,0);
    else dp[x][y]=rec(x-1,0)+rec(x-1,1);

    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y,a,b,c;

    FOR(i,1,44)
    {
      ar[i]=rec(i,0);
    }



        mem(prin,0);
        cin>>x>>y;

        if(y>ar[x])
        {
            cout<<-1<<NL;
            return 0;
        }
        while(true)
        {
           a=lower_bound(ar,ar+45,y)-ar;
           if(y<=1) break;
           else if(y==2)
           {
               prin[1]=1;
               break;
           }
           else
           {
               prin[a]=1;
               y-=ar[a-1];
           }
        }
        REV(i,x,1) cout<<prin[i];
        cout<<NL;
    return 0;
}


