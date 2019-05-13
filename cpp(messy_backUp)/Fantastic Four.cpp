#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
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
#define MAX 50005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

struct info
{
   LL val;

}tree[4*MAX];
LL arr[50010];

void init(LL idx, LL b, LL e )
{
    if( b == e )
    {
        cnd.val = arr[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.val =  max(tree[lnd].val,tree[rnd].val);
}

LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return maxx;
    if(st <= b && en >= e)
        return cnd.val;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
}

void update_node(int idx, int b, int e, LL v)
{
    cnd.val = v;
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
    cnd.val = max(tree[lnd].val,tree[rnd].val);
}

vector<int> mat[50010];
pr pp[50010];
LL ooh[50010], pos[50010], com[10000];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tt;
    cin>>tt;
    FOR(t,1,tt)
    {
        LL i, j, a, b, c, d, x, y, z, n, k, ans = maxx, s, e;
        cin>>n;
        FOR(i,1,n) cin>>arr[i], pp[i].F=arr[i], pp[i].S=i;
        FOR(i,1,n-1)
        {
            cin>>x>>y;
            mat[x].PB(y);
            mat[y].PB(x);
        }
        sort(pp+1,pp+n+1);
        FOR(i,1,n) ooh[i]=pp[i].F, pos[i]=pp[i].S;
        init(1,1,n);
        FOR(i,1,n)
        {
            update(1,1,n,i,i,0);
            FOR(j,1,mat[i].size())
            {
                k=mat[i][j-1];
                update(1,1,n,k,k,0);
            }
            x = query(1,1,n,1,n);
            x = lower_bound(ooh+1,ooh+n+1,x)-ooh;
            cout << pos[x] << ' ';
            update(1,1,n,i,i,arr[i]);
            FOR(j,1,mat[i].size())
            {
                k=mat[i][j-1];
                update(1,1,n,k,k,arr[k]);
            }
        }
        FOR(i,1,n)mat[i].clear();
        cout << endl;
    }
    return 0;
}


