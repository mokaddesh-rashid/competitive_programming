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
   LL val;

}tree[4*MAX];
LL arr[100010];

void update_node(int idx, int b, int e, LL v)
{
    cnd.val=v;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
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

vector<int>mat[MAX];
int main()
{
    ios::sync_with_stdio(false);

    int n, k, a, b, c, x;

    cin>>n>>k;
    FOR(i,1,n)
    {
       cin>>a;
       x=max(query(1,1,MAX,0,a-(k+1)), query(1,1,MAX,a+k+1,MAX));
       mat[x+1].PB(a);
       update(1,1,MAX,a,a,x+1);
    }

    FOR(i,1,MAX-1)
    {
        sort(mat[i].begin(),mat[i].end());
        FOR(j,0,(int)mat[i].size()-1) cout<<mat[i][j]<<' ';
    }
    return 0;
}
