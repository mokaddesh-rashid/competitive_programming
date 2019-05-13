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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct Node{
    LL lazy, val;
};

Node tree[4*MAX];
int arr[MAX];

void init(LL idx, LL b, LL e )
{
    if(b==e)
    {
        cnd.val = arr[b];
        return ;
    }
    init(lnd, b, (b+e)>>1);
    init(rnd, ((b+e)>>1)+1, e);
    cnd.val=min(tree[lnd].val,tree[rnd].val);
}

void update_node(int idx, int b, int e, LL v)
{
    cnd.val += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    if(cnd.lazy!=0)
    {
        update_node(lnd, b, (b+e)>>1, cnd.lazy);
        update_node(rnd, ((b+e)>>1)+1, e, cnd.lazy);
        cnd.lazy = 0;
    }
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return (1<<30);
    if(st <= b && en >= e)
        return cnd.val;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return min(lft,rgt);
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
    cnd.val = min(tree[lnd].val,tree[rnd].val);
}

int ar[MAX];
int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c=0,d,x,st,en,mid,e;

    sff(n,m);//cin>>n>>m;
    FOR(i,1,n) sf(arr[i]);///cin>>arr[i];
    sort(arr+1,arr+n+1,greater<int>());
    init(1,1,n);

    FOR(i,1,m) sf(ar[i]);///cin>>ar[i];
    FOR(i,1,m)
    {
       e=d=x=ar[i];

       x=query(1,1,n,ar[i],ar[i]);

       if(x==0||ar[i]>n) break;
       c++;
       st=ar[i]; en=n;
       while(st<=en)
       {
           mid=(st+en)>>1;
           a=query(1,1,n,mid,mid);
           if(a==x) st=mid+1, d=max(d,mid);
           else en=mid-1;
       }

       st=1; en=ar[i];
       while(st<=en)
       {
           mid=(st+en)>>1;
           a=query(1,1,n,mid,mid);
           if(a==x) en=mid-1, e=min(e,mid);
           else st=mid+1;
       }
       a=abs(ar[i]-e)+1;
       update(1,1,n,1,e-1,-1);
       update(1,1,n,d-a+1,d,-1);
       ///FOR(i,1,n) cout<<query(1,1,n,i,i)<<' ';
       ///cout<<NL;
    }
    pf("%d",c);
    ///cout<<c<<NL;
    return 0;
}
