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
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

struct info
{
   int sum;

}tree[4*MAX];
int arr[100010];

void init(int idx, int b, int e )
{
    if( b == e )
    {
        cnd.sum = arr[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum =  tree[lnd].sum + tree[rnd].sum ;
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, int v)
{
    cnd.sum=0;
}
int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
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

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}
int val[100010],ac[100010],up[100010],ans[100010];
pr del[100010];

struct infa
{
    int l,r,p,i;
}qr[100010];
class compare
{
public:
    bool operator()(infa x,infa y)
    {
        return x.p<y.p;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(arr,0); mem(val,0);
        int n,m,i,j,a,b,c,d,x,y,z,u,p,w;
        cin>>n>>m;
        FOR(i,1,n) cin>>val[i];
        a=b=c=0;
        FOR(i,1,n)
        {
            a++;
            ac[i]=a;
            if(val[i]!=val[i+1])
            {
                //cout<<'a'<<i<<NL;
                arr[i]=1;
                del[c].F=a; del[c].S=i; c++;
                a=0;
            }
        }
        REV(i,n,1)
        {
            if(arr[i]==1) a=ac[i];
            up[i]=a;
        }
        //FOR(i,1,n) cout<<ac[i]<<' '<<up[i]<<NL;
        init(1,1,n);
        FOR(i,0,m-1)
        {
            cin>>qr[i].l>>qr[i].r>>qr[i].p;
            qr[i].i=i;
        }
        sort(qr,qr+m,compare()); sort(del,del+c);
        x=0;
        FOR(i,0,m-1)
        {
            while(x<c&&del[x].F<qr[i].p)
            {
                //cout<<'d'<<del[x].S<<NL;
                update(1,1,n,del[x].S,del[x].S,0);
                x++;
            }
            a=query(1,1,n,qr[i].l,qr[i].r);
            d=ac[qr[i].l]; w=up[qr[i].l]; y=w-d;
            u=ac[qr[i].r]; p=up[qr[i].p]; z=p-u;
            if(qr[i].l+y>=qr[i].r)
            {
                y=qr[i].r-qr[i].l+1;
                if(y>=qr[i].p)a=1;
            }
            else
            {
                if(up[qr[i].l]>=qr[i].p)a--;
                y=up[qr[i].l]-ac[qr[i].l]+1;
                if(y>=qr[i].p) a++;
                if(ac[qr[i].r]!=up[qr[i].r]&&ac[qr[i].r]>=qr[i].p) a++;
            }
            ans[qr[i].i]=a;
        }
        FOR(i,0,m-1) cout<<ans[i]<<NL;
    }
    return 0;
}
