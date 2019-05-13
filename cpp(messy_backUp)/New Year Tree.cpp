#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 1000005
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

struct Node{
    LL sum;
    LL lazy;
};
LL ar[1000010], ooh[1000010];
Node tree[4*MAX];
void init(LL idx, LL b, LL e)
{
    if(b==e)
    {
        //if(b==2)cout<<b<<' '<<ar[b]<<endl;
        cnd.sum=ooh[b];
        return;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.sum = tree[lnd].sum|tree[rnd].sum;

}
void update_node(LL idx, LL b, LL e, LL v)
{
    cnd.sum = v;
    cnd.lazy = v;
}

void lazy_update(LL idx, LL b, LL e)
{
    if(cnd.lazy!=0)
    {
        update_node(lnd, b, (b+e)>>1, cnd.lazy);
        update_node(rnd, ((b+e)>>1)+1, e, cnd.lazy);
    }
    cnd.lazy = 0;
}


LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return (lft|rgt);
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
    cnd.sum = tree[lnd].sum|tree[rnd].sum;
}

vector<int>mat[400010];
int vis[400010], pos, lft[400010], rgt[400010];

int dfs(int p)
{
    vis[p]=1;
    ooh[pos]=ar[p];lft[p]=pos; pos++;
    int i, j, n=mat[p].size();
    FOR(i,0,n-1)
    {
        int x=mat[p][i];
        if(vis[x]==0) dfs(x);
    }
    ooh[pos]=ar[p];rgt[p]=pos; pos++;

}
int main()
{
   //ios::sync_with_stdio(false);
   LL i, j, a, b, c, x, y, z, n, m;
   sff(n,m);//cin>>n>>m;
   FOR(i,1,n) sf(ar[i]), ar[i]=(LL)1<<ar[i];
   FOR(i,1,n-1)
   {
       sff(x,y);
       mat[x].PB(y);
       mat[y].PB(x);
   }
   pos=1;
   dfs(1);
   init(1,1,1000000);
   FOR(i,0,m-1)
   {
       sf(a);
       if(a==1)
       {
           sff(x,y);
           y=(LL)1<<y;
           //cout<<y<<endl;
           update(1,1,1000000,lft[x],rgt[x],y);
       }
       else
       {
           sf(x);
           x=query(1,1,1000000,lft[x],rgt[x]);
           c=0;
           //cout<<x<<endl;
           FOR(j,0,61)
           {
               y=(LL)1<<j;
               if(x&y)c++;
               //if(x&y) cout<<j<<' ';
           }
           pf("%I64d\n",c);
       }
   }
}



