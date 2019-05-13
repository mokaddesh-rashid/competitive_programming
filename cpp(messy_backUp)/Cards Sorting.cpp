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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
   LL sum;

}tree[4*MAX];
LL arr[100010];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum=1;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

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

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

pr ar[sz];
vector<int>mat[sz];
int ase[sz];

int main()
{
    int i,j,n,a,b,x,y,z;
    LL c=0;

    cin>>n;
    FOR(i,1,n)
    {
        cin>>ar[i].F, ar[i].S=i;
        mat[ar[i].F].PB(i);

    }
    sort(ar+1,ar+n+1);

    x=1;
    FOR(i,1,n)
    {
       y=ar[i].S;
       if(i>1&&ar[i-1].F!=ar[i].F)
       {

       }
       if(y>=x)
       {
           ///cout<<y<<' '<<x<<' '<<query(1,1,n,x,y)<<NL;
           a=query(1,1,n,x,y);
           b=(y-x+1)-a;
           c+=b;
           x=y;
           update(1,1,n,y,y,1);
       }
       else
       {
           a=query(1,1,n,x,n);
           c+=(n-x+1)-a;
           x=1;
           ///cout<<y<<' '<<x<<' '<<query(1,1,n,x,y)<<NL;
           a=query(1,1,n,x,y);
           b=(y-x+1)-a;
           c+=b;
           x=y;
           update(1,1,n,y,y,1);
       }
    }
    cout<<c<<NL;

    return 0;
}

