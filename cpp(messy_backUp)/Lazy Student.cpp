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

int next[sz];

struct node
{
    int first,second,p;
}ar[sz],ed[sz];

class compare
{
public:
    bool operator()(node x,node y)
    {
        if(x.S==y.S) return x.F<y.F;
        else return x.S<y.S;
    }
};
int val[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(i,1,100005)next[i]=1;
    int i,j,x,y,n,m,a,b,c=0,p=2,d=0;

    cin>>n>>m;
    FOR(i,0,m-1)
    {
        cin>>a>>b;
        if(b==0) b=1;
        else b=0;
        ar[i].F=a; ar[i].S=b; ar[i].p=i;
        if(ar[i].S==0) c++;
    }
    sort(ar,ar+m,compare());
//    FOR(i,0,m-1)
//    {
//        cout<<ar[i].F<<' '<<ar[i].S<<' '<<NL;
//    }
    if(c!=n-1)
    {
        cout<<-1<<NL;
        return 0;
    }

    FOR(i,0,n-2)
    {
        val[p]=ar[i].F; a=ar[i].p;
        ed[a].F=p; ed[a].S=p-1;
        p++;
    }

    p=3;
    FOR(i,n-1,m-1)
    {
        while(p-next[p]<=1)
        {
            p++;
        }
        if(val[p]>ar[i].F) d=1; a=ar[i].p;
        ed[a].F=p; ed[a].S=next[p];
        next[p]++;
    }
    if(d==1) cout<<-1<<NL;
    else
    {
        FOR(i,0,m-1) cout<<ed[i].F<<' '<<ed[i].S<<NL;
    }
    return 0;
}
