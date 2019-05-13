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

struct node
{
    int l, r, p;
}query[MAX];
int block;

class Compare
{
public:
    bool operator()( node f, node s )
    {
      if( f.l/block != s.l/block ) return f.l/block < s.l/block;
      return f.r < s.r;
    }
};

LL ar[MAX],samne[MAX],pise[MAX],ty[MAX],used[MAX],cnt[MAX*5],v,x,y;
map<LL,LL>mopa;
LL val[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,n,k,m,q,c=0,px,py;

    cin>>n>>k; block=sqrt(n);
    FOR(i,1,n)cin>>ty[i],ty[i]--;
    FOR(i,1,n)
    {
        cin>>ar[i];
        if(ty[i])ar[i]*=-1;
        val[i]=ar[i];
        ar[i]=ar[i]+ar[i-1];
    }

    FOR(i,1,n) samne[i]=ar[i-1]+k;
    FOR(i,1,n) pise[i]=ar[i-1]+k;

    FOR(i,1,n)cout<<samne[i]<<' '<<pise[i]<<NL;


    return 0;
}
