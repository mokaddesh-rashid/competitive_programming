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

LL dp[MAX], ar[MAX], n;

LL rec(int p)
{
    if(p==n) return 0;
    if(dp[p]!=-1) return dp[p];

    LL temp=maxx, a, b;
    a=lower_bound(ar,ar+n,ar[p]+50)-ar;
    b=lower_bound(ar,ar+n,ar[p]+1440)-ar;

    temp=20+rec(p+1);
    temp=min(temp,50+rec(a));
    temp=min(temp,120+rec(a));

    return dp[p]=temp;

}

//void prin(int p,LL v)
//{
//    cout<<p<<' '<<v<<NL;
//    if(p==n) return;
//
//    LL temp=maxx, a, b;
//    a=lower_bound(ar,ar+n,ar[p]+50)-ar;
//    b=lower_bound(ar,ar+n,ar[p]+1440)-ar;
//
//    if(rec(p)==20+rec(p+1))
//    {
//        v+=20;
//        cout<<v<<"  k "<<p+1<<NL;
//        prin(p+1,v);
//    }
//    else if(rec(p)==50+rec(a))
//    {
//        v+=50;
//        cout<<v<<NL;
//        prin(a,v);
//    }
//    else if(rec(p)==120+rec(b))
//    {
//        v+=120;
//        cout<<v<<NL;
//        prin(b,v);
//    }
//
//
//    return ;
//
//}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m,x,c=0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    n--;
    x=rec(0);
    cout<<x<<NL;
    ///prin(0,0);
    FOR(i,0,n-1)
    {
      /// x=rec()
    }
    return 0;
}


