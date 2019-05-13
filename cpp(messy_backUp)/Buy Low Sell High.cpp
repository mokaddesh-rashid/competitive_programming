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
#define MAX 2010
#define SZ 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   LL mn;
}tree[4*MAX];

int ar[MAX];

void update_node(int idx, int b,int v)
{
    ar[b]=v; cnd.mn=b;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.mn;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if(ar[lft]<ar[rgt]) return lft;
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

    update(lnd, b, (b+e)/2, st, v);
    update(rnd, ((b+e)/2)+1, e, st, v);

    if( ar[tree[lnd].mn] < ar[tree[rnd].mn] ) cnd.mn=tree[lnd].mn;
    else cnd.mn=tree[rnd].mn;
}

pr sh[MAX];
class compare
{
public:
    bool operator()(pr x,pr y)
    {
        if(x.F==y.F)return x.S<y.S;
        else return x.F>y.F;
    }
};

int main()
{
    ios::sync_with_stdio(false);
//    /inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,x,y,n,m,a,b,c=0,p,q=0;
        cin>>n;

        FOR(i,1,n)cin>>sh[i].F,sh[i].S=i;
        FOR(i,1,n)
        {
            ///cout<<i<<' '<<sh[i].F<<NL;
            a=sh[i].F;
            update(1,0,MAX,i,a);
        }
        update(1,0,MAX,0,mod);
        sort(sh+1,sh+n+1,compare());
        //FOR(i,1,n)cout<<sh[i].F<<' '<<sh[i].S<<NL;
    //    //FOR(i,0,n)cout<<ar[query(1,0,MAX,i,i)]<<NL;

        FOR(i,1,n)
        {
            a=sh[i].S;
            b=query(1,0,MAX,1,a);
            ///cout<<a<<' '<<b<<NL;
            if(ar[b]!=mod&&ar[a]!=mod){
                c+=(ar[a]-ar[b]);
                update(1,0,MAX,a,mod);
                update(1,0,MAX,b,mod);
            }
        }
        cout<<c<<NL;
    }

    return 0;
}

