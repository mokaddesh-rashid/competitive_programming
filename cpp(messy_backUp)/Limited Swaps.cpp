
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
#define SZ 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   int mx,sum;
}tree[4*MAX];

int ar[MAX],br[MAX];

void update_node(int idx, int b)
{
    cnd.mx=b; cnd.sum=br[b];
}


void update(int idx, int b, int e, int pos)
{
    if(pos > e || pos < b ) return ;
    if(pos == b && pos == e)
    {
        update_node(idx, b);
        return ;
    }

    update(lnd, b, (b+e)/2, pos);
    update(rnd, ((b+e)/2)+1, e, pos);

    cnd.sum=tree[lnd].sum+tree[rnd].sum;

    if( ar[tree[lnd].mx] >= ar[tree[rnd].mx] ) cnd.mx=tree[lnd].mx;
    else cnd.mx=tree[rnd].mx;
}

int query_max(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e) return cnd.mx;

    int lft = query_max(lnd, b, (b+e)/2, st, en);
    int rgt = query_max(rnd, ((b+e)/2)+1, e, st, en);

    if(ar[lft]>=ar[rgt]) return lft;
    return rgt;
}

int query_sum(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e) return cnd.sum;

    int lft = query_sum(lnd, b, (b+e)/2, st, en);
    int rgt = query_sum(rnd, ((b+e)/2)+1, e, st, en);

    return lft+rgt;
}

int up(int k,int n,int p)
{
    int st,en,mid,a=p,b,c;

    st=1;en=n;
    while(st<=en)
    {
        mid=(st+en)>>1;
        c=query_sum(1,1,MAX,1,mid);
        if(c<k)st=mid+1;
        else en=mid-1;
        if(c<=k) a=max(mid,a);
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,n,k,a,b,c;
    cin>>n>>k;

    FOR(i,1,n)
    {
        cin>>ar[i];br[i]=1;
        update(1,1,MAX,i);
    }

    i=1;
    while(i<=n)
    {
        while(ar[i]==-1&&i<=n)
        {
            i++;
        }
        //cout<<i<<NL;
        if(i<=n)
        {
            a=up(k+1,n,i);
            //cout<<a<<NL;
            b=query_max(1,1,MAX,i,a);
            if(!(ar[i]<ar[b]))b=i;
            cout<<ar[b]<<' ';
            k-=query_sum(1,1,MAX,i+1,b);
            ar[b]=-1;br[b]=0;
            update(1,1,MAX,b);
        }
    }
    return 0;
}
