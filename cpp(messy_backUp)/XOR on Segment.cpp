#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
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
    int lazy;
};
int ar[100010];
Node tree[4*MAX];
void init(int idx, int b, int e)
{
    if(b==e)
    {
        //if(b==2)cout<<b<<' '<<ar[b]<<endl;
        cnd.sum=ar[b];
        return;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
    cnd.lazy=0;

}
void update_node(int idx, int b, int e, int v)
{
    if(v%2==1)cnd.sum = ((e-b+1)-cnd.sum);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    if(cnd.lazy!=0)
    {
        update_node(lnd, b, (b+e)>>1, cnd.lazy);
        update_node(rnd, ((b+e)>>1)+1, e, cnd.lazy);
    }
    cnd.lazy = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
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
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}
LL ans[100010];
int q[50010][5], ooh[100010];
int main()
{
   LL i, j, a, b, c, x, y, z, n, m, p;
   cin>>n;
   FOR(i,1,n)cin>>ooh[i];
   mem(ans,0);
   cin>>m;
   FOR(i,0,m-1)
   {
       cin>>q[i][0];
       if(q[i][0]==1) cin>>q[i][1]>>q[i][2];
       else cin>>q[i][1]>>q[i][2]>>q[i][3];
   }
   FOR(t,0,21)
   {
       p=0;
       //mem(tree,0);
       //mem(ar,0);
       FOR(i,0,n) {
           ar[i]=0;
           if(ooh[i]&1<<t)ar[i]=1;
       }
       init(1,1,n);
       //cout<<endl;
       FOR(i,0,m-1)
       {
           if(q[i][0]==1)
           {
               x=q[i][1]; y=q[i][2];
               ans[p]+=(query(1,1,n,x,y)*(1<<t));
               //if(i==0)cout<<query(1,1,n,2,2)<<endl;
               p++;
           }
           else if(q[i][3]&(1<<t))
           {
               x=q[i][1]; y=q[i][2];
               update(1,1,n,x,y,1);
               //if(i==0)cout<<query(1,1,n,2,2)<<endl;

           }
       }
   }
   FOR(i,0,p-1) cout<<ans[i]<<endl;
}


