#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
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
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

struct info
{
   LL sum;

}tree[4*MAX];
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
}
void update_node(int idx, int b, int e, LL v)
{
    cnd.sum = v;
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
    cnd.sum = max(tree[lnd].sum,tree[rnd].sum);
}

pr ar[100010];
int br[100010], lola[100010], riga[100010];
int main()
{
    //outf;
    int tc, n;
    cin>>tc;
    FOR(t,1,tc)
    {
        cin>>n;
        int x=1, ans=1;
        FOR(i,0,n-1) cin>>ar[i].F, ar[i].S=i;
        sort(ar,ar+n);
        FOR(i,0,n-1)
        {
            if(i>0&&ar[i-1].F!=ar[i].F)x++;
            br[ar[i].S]=x;
        }
        //FOR(i,0,n-1) cout<<br[i]<<' ';
        //cout<<endl;
        mem(tree,0);
        FOR(i,0,n-1)
        {
            lola[i]=query(1,1,n,1,br[i]-1)+1;
            update(1,1,n,br[i],br[i],lola[i]);
            //cout<<lola[i]<<' ';
        }
        mem(tree,0);
        REV(i,n-1,0)
        {
            riga[i]=query(1,1,n,1,br[i]-1)+1;
            update(1,1,n,br[i],br[i],riga[i]);
        }
        FOR(i,0,n-1)
        {
            x=min(lola[i],riga[i]);
            ans=max(ans,x);
        }
        cout<<"Case "<<t<<": "<<((ans*2)-1)<<endl;//cout<<mat[n][m]<<endl;
    }
    return 0;
}



