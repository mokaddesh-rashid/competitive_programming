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
#define MAX 200010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
    int x,y,p;

}ar[MAX];
int p=0;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,p=1,a,b,c;

    cin>>n>>m;

    FOR(i,2,n)
    {
        ar[p].x=i-1; ar[p].y=i; ar[p].p=p;
        p++;
    }

    a=1; b=3;
    c=n-1;
    while(c>m&&a<n)
    {
       if(b>n)
       {
           a++;
           b=a+2;
       }
       else
       {
           cout<<a<<' '<<b<<NL;
           ar[p].x=a; ar[p].y=b; ar[p].p=p;
           p++;
           b++;
           c--;
       }

    }
    if(c!=m)
    {
        cout<<-1<<NL;
        return 0;
    }
    cout<<p-1<<NL;
    FOR(i,1,p-1)cout<<ar[i].x<<' '<<ar[i].y<<' '<<ar[i].p<<NL;
    return 0;
}


