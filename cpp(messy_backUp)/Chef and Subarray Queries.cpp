#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
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
typedef pair<LL,LL> pr;

struct Node{
    LL lazy, val, roa;
};

Node tree[4*MAX];
LL ar[MAX];

void init(LL idx, LL b, LL e )
{
    if(b==e)
    {
        ar[b]=0;
        cnd.val = b;
        cnd.roa = 0;
        return ;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.val=tree[lnd].val+tree[rnd].val;
    cnd.lazy=0;
}

void update_node(LL idx, LL b, LL e, LL v)
{
    cnd.val += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(LL idx, LL b, LL e)
{
    if(cnd.lazy!=0)
    {
        update_node(lnd, b, (b+e)>>1, cnd.lazy);
        update_node(rnd, ((b+e)>>1)+1, e, cnd.lazy);
        cnd.lazy = 0;
    }
}

LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return lft+rgt;
}

void update(LL idx, LL b, LL e, LL st, LL en, LL v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    lazy_update(idx, b, e);
    update(lnd, b, (b+e)>>1, st, en, v);
    update(rnd, ((b+e)>>1)+1, e, st, en, v);
    cnd.val = tree[lnd].val+tree[rnd].val;
}

LL n,q,L,R,ans[MAX],call;
struct babe
{
    LL ty,l,r;
}in[MAX];
set<int>sota;

void solve(LL v)
{
    LL a,b,nx,c;

    while(!sota.empty())
    {
        sota.erase(sota.begin());
    }
    ///init(1,1,MAX-1);
    sota.insert(n+1);

    FOR(i,1,q)
    {

        if(in[i].ty==1)
        {
           a=in[i].l; b=in[i].r;
           if(ar[a]>v)
           {
               if(b>v)ar[a]=b;
               else
               {
                   ar[a]=b;
                   sota.erase(a);
                   nx=*(sota.lower_bound(a));
                   c=query(1,1,MAX-1,a-1,a-1);
                   update(1,1,MAX-1,a,nx-1,c+1);
               }
           }
           else
           {
              if(b<=v)ar[a]=b;
              else
              {
                 ar[a]=b;
                 nx=*(sota.lower_bound(a));
                 c=query(1,1,MAX-1,a,a);
                 update(1,1,MAX-1,a,nx-1,c*-1);
                 sota.insert(a);
              }
           }
        }
        else
        {
            LL  p,q;
            p=query(1,1,MAX-1,in[i].l,in[i].r);
            nx=*(sota.lower_bound(in[i].l));
            nx=min(nx,in[i].r+1);
            q=query(1,1,MAX-1,in[i].l-1,in[i].l-1)*(nx-in[i].l);
            p-=q;
            if(call==0)ans[i]+=p;
            else ans[i]-=p;
        }
    }
    call++;
}


int main()
{
    //ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j;

    sf(n);sf(q);sf(L);sf(R);///cin>>n>>q>>L>>R;
    FOR(i,1,q)sf(in[i].ty), sf(in[i].l), sf(in[i].r);
    solve(R); //=mem(tree,0);
    solve(L-1);
    //FOR(i,1,q)if(in[i].ty==2)pf("%lld\n",ans[i]);

    return 0;
}


