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
#define mod          1000000000
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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int>sota[MAX+10];
map<int,int> col;
int due,val[MAX+10],n;
int dp[MAX];


int rec(int p)
{
   if(p>n)return 0;

   int f=p*2, s=p*2+1, x=val[p], y;
   y=col[x];

   if(y!=due)
   {
       col[x]=due;
       return 1+rec(f)+rec(s);
   }
   return rec(f)+rec(s);

}
int main()
{
    ios::sync_with_stdio(false);
   /// inf;
   /// outf;
        mem(dp,-1);
        int i,j,m,v,p;

        cin>>n>>m;
        FOR(i,1,n)
        {
            cin>>val[i];
        }
        FOR(i,1,m)
        {
            due=i;
            cin>>v;
            if(dp[v]==-1)dp[v]=rec(v);
            cout<<dp[v]<<NL;
        }

    return 0;
}



