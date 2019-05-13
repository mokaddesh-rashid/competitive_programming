#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
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
#define MAX 500010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


class Compare
{
public:
    bool operator()(LL x,LL y)
    {
        return x>y;
    }
};
set<LL,Compare>mota,sota;
LL ar[MAX],cnt[MAX];

int main()
{
    //ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j,n,m;
    LL c=0,a,b,x,y;

    sf(n);
    FOR(i,0,n-1)sf(ar[i]),mota.insert(ar[i]);

    while(true)
    {
        a=b=0;
        if(!mota.empty())a=*(mota.begin());
        if(!sota.empty())b=*(sota.begin());

        x=max(a,b); y=min(a,b);
        if(x<=1)break;


            if(mota.find(a/2)==mota.end()) sota.insert(a/2);
            mota.erase(a);
            if(a>1)c++;

            if(mota.find(b/2)==mota.end()) sota.insert(b/2);
            sota.erase(b);
            if(b>1)c++;

    }

    pf("%lld\n",c);
    return 0;
}


