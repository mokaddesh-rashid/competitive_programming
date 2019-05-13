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
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define MAX 200010
typedef pair<int,int> pr;

pr tree[4*MAX],no;
int ar[100010];

pr merge_it(pr a, pr b)
{
    if(a.F==0) return b;
    if(b.F==0) return a;
    if(ar[a.F]!=ar[a.S]) return a;
    if(ar[b.F]!=ar[b.S]) return b;
    a.S=b.S;
    return a;
}
void init(LL idx, LL b, LL e )
{
    if(b==e)
    {
        cnd.F=cnd.S=b;
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd=merge_it(tree[lnd],tree[rnd]);
}

pr query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return no;
    if(st <= b && en >= e)
        return cnd;

    pr lft = query(lnd, b, (b+e)/2, st, en);
    pr rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return merge_it(lft,rgt);
}
int main()
{
    //ios::sync_with_stdio(false);
    pr ole;
    no.F=0; no.S=0;
    int n,m,a,b,c;
    sff(n,m);//cin>>n>>m;
    FOR(i,1,n) sf(ar[i]);//cin>>ar[i];
    init(1,1,n);
    FOR(i,1,m)
    {
        sfff(a,b,c);///cin>>a>>b>>c;
        ole=query(1,1,n,a,b);
        if(ar[ole.F]==ar[ole.S]&&ar[ole.F]==c) pf("-1\n");///cout<<-1<<NL;
        else if(ar[ole.F]!=c) pf("%d\n",ole.F);///cout<<ole.F<<NL;
        else pf("%d\n",ole.S);///cout<<ole.S<<NL;
    }
    return 0;
}
