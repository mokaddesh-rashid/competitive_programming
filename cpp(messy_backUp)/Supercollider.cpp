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
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct Node
{
    LL lazy, sum;
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    update_node(lnd, b, (b+e)/2, cnd.lazy);
    update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    cnd.lazy = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
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
    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

struct info
{
    int a,b,c,d,p;
};
info xt[100010], yt[100010];
int ans[100010];
class Compare
{
public:
    bool operator()(info f,info s)
    {
        return f.a<s.a;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c,d,p=0,q=0;
    info in;
    cin>>q>>p;

    FOR(i,0,q-1)
    {
        cin>>in.a>>in.b>>x;
        in.c=in.a; in.d=in.b+x;
        yt[i]=in;
    }
    FOR(i,0,p-1)
    {
        cin>>in.a>>in.b>>x;
        in.c=in.a+x; in.d=in.b;
        xt[i]=in;
    }
    a=b=c=0;
    sort(yt,yt+q,Compare());
    sort(xt,xt+p,Compare());
    FOR(i,0,p-1)
    {
        while(b<q)
        {
            if(xt[i].a<=yt[b].a&&yt[b].a<=xt[i].c)
            {
                update(1,1,100000,yt[b].b,yt[b].d,1);
                b++;
            }
            else  break;
        }
        while(a<b)
        {
            if(yt[a].a<xt[i].a)
            {
                update(1,1,100000,yt[b].b,yt[b].d,-1);
                a++;
            }
            else  break;
        }
        x=query(1,1,100000,xt[i].b,xt[i].b);
        c+=x; //ans[xt[i].p]=x;
    }
    cout<<c<<NL;
    //FOR(i,0,n-1) ans[i]<<' ';
    return 0;
}



