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

struct info
{
   LL mx;
}tree[4*MAX];

int ar[sz];

void update_node(int idx, int b)
{
    ar[b]=1; cnd.mx=b;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.mx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if(ar[lft]>ar[rgt]) return lft;
    return rgt;
}

void update(int idx, int b, int e, int st)
{
    if(st > e || st < b ) return ;
    if(st == b && st == e)
    {
        update_node(idx, b);
        return ;
    }

    update(lnd, b, (b+e)/2, st);
    update(rnd, ((b+e)/2)+1, e, st);

    if( ar[tree[lnd].mx] > ar[tree[rnd].mx] ) cnd.mx=tree[lnd].mx;
    else cnd.mx=tree[rnd].mx;
}

pr sh[sz];
int ans[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c;
    cin>>n;
    FOR(i,1,n)
    {
        cin>>sh[i].F; sh[i].S=i;
    }
    sort(sh+1,sh+n+1);
    a=1;
    FOR(i,1,n)
    {
        x=query(1,1,n,sh[i].S+1,n);
        if(sh[i].F!=sh[i+1].F)
        {
            while(a<=i)
            {
               //cout<<sh[a].S<<NL;
               update(1,1,n,sh[a].S);
               a++;
            }
        }
       // cout<<sh[i].S<<' '<<x<<' '<<ar[x]<<NL;
        if(ar[x]==0) ans[sh[i].S]=-1;
        else ans[sh[i].S]=x-sh[i].S-1;
    }
    FOR(i,1,n) cout<<ans[i]<<' ';
    return 0;
}

