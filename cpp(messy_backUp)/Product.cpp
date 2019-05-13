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

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,n,m,a,b,c;
    double p,q,r,t;
    while(cin>>n>>m)
    {
        p=0;
        a=(n-m); b=m; x=max(a,b); y=min(a,b);
        while(n>x)
        {
           q=log(n)/log(10);
           p+=q;
           ///cout<<n<<' '<<p<<NL;
           n--;
        }
        while(y>0)
        {
            q=log(y)/log(10);
            p-=q;
            ///cout<<y<<' '<<p<<NL;
            y--;
        }
        q=pow(10,p); x=q; r=x;
        if(q-r>.01)x++;
        t=x;cout<<x<<NL;

        cin>>n>>m;
        p=0;
        a=(n-m); b=m; x=max(a,b); y=min(a,b);
        while(n>x)
        {
           q=log(n)/log(10);
           p+=q;
           ///cout<<n<<' '<<p<<NL;
           n--;
        }
        while(y>0)
        {
            q=log(y)/log(10);
            p-=q;
            ///cout<<y<<' '<<p<<NL;
            y--;
        }
        q=pow(10,p); y=q; r=x;
        if(q-r>.01)y++;
        q=y;
        //cout<<y<<NL;
        cout<<fixed;
        cout<<setprecision(6)<<t/q<<NL;
    }
    return 0;
}


