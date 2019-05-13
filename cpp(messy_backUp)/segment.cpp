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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct Node{
    int mp;
};

Node tree[4*MAX];
int ar[MAX];

void update_node(int idx, int b, int e)
{
    cnd.mp=b;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e) return cnd.mp;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if(ar[lft]>=ar[rgt])return lft;
    else return rgt;
}

void update(int idx, int b, int e, int st)
{
    if(st > e || st < b ) return ;
    if(st <= b && st >= e)
    {
        update_node(idx, b, e);
        return ;
    }

    update(lnd, b, (b+e)/2, st);
    update(rnd, ((b+e)/2)+1, e, st);

    if(ar[tree[lnd].mp]>=ar[tree[rnd].mp]) cnd.mp=tree[lnd].mp;
    else cnd.mp=tree[rnd].mp;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,n,m,a,b,c,d=0,x,y;

    cin>>n;

    FOR(i,0,n-1)
    {
        cin>>a;
        ar[a]++;
        d=max(ar[a],d);
        x=min(x,a);
    }
    FOR(i,1,MAX-1)update(1,1,MAX,i);
    c=(n)%2+(n)/2;

    if(d>c)
    {
        cout<<-1<<NL;
        return 0;
    }

    x=y=a; d=-1;
    FOR(i,0,n-1)
    {
        while(ar[y]==0&&y<x)
        {
            y++;
            if(x==y)x++;
        }
        while(ar[x]==0&&x<MAX)
        {
            x++;
        }
        a=query(1,1,MAX,1,n); b=ar[a];
        c=(n-i)%2+(n-i)/2;

        if((n-i)%2&&b==c);
        else if(y!=d) a=y;
        else a=x;

        cout<<a<<' ';
        ar[a]--;
        update(1,1,MAX,a);
        d=a;
    }
    return 0;
}
