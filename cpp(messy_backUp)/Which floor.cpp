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


pr ar[MAX];
int cnt[MAX],m,n;

int rec(int v)
{
    int a,b,c;
    FOR(i,0,m-1)
    {
        a=ar[i].F/v;
        if(ar[i].F%v)a++;
        if(a!=ar[i].S) return 0;
    }
    a=n/v;
    if(n%v)a++;
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,a,b,c=0,y,z;
    LL x=pow(31,9);
    cout<<x<<NL;

    ///cin>>n>>m;
//    FOR(i,0,m-1)cin>>ar[i].F>>ar[i].S;
//
//    FOR(i,1,220)
//    {
//        c=rec(i);
//        cnt[c]++;//cout<<i<<NL
//    }
//
//    a=0;
//    FOR(i,1,220)
//    {
//        if(cnt[i]!=0) a++, c=i;
//    }
//
//    if(n==1)cout<<1<<NL;
//    else if(a==1&&m!=0)
//    {
//        cout<<c<<NL;
//    }
//    else cout<<-1<<NL;
    return 0;
}


