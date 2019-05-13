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
#define NL "\n"
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define SZ 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   LL mx;
}tree[4*MAX];

int ar[MAX];

void update_node(int idx, int b,int v)
{
    ar[b]=v; cnd.mx=b;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.mx;

    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);

    if(ar[lft]>=ar[rgt]) return lft;
    return rgt;
}

void update(int idx, int b, int e, int st,int v)
{
    if(st > e || st < b ) return ;
    if(st == b && st == e)
    {
        update_node(idx, b, v);
        return ;
    }

    update(lnd, b, (b+e)>>1, st, v);
    update(rnd, ((b+e)>>1)+1, e, st, v);

    if( ar[tree[lnd].mx] >= ar[tree[rnd].mx] ) cnd.mx=tree[lnd].mx;
    else cnd.mx=tree[rnd].mx;
}

pr sh[MAX];
int ans[MAX],stk[MAX],top;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c,p;
    sf(n);//cin>>n;
    FOR(i,1,n)
    {
        sf(a);//cin>>a;
        update(1,1,n,i,a);
    }

    p=c=n;
    top=-1;
    while(c>0)
    {
        a=query(1,1,n,1,p);
        if(ar[a]==0)
        {
            p=n;
            while(top>-1)
            {
                pf("%d ",stk[top]);
                top--;
            }
            pf(NL);
        }
        else
        {
            stk[++top]=ar[a];
            update(1,1,n,a,0);
            p=a-1;
            c--;

        }

    }
    while(top>-1)
    {
        pf("%d ",stk[top]);
        top--;
    }
    pf(NL);
    return 0;
}



