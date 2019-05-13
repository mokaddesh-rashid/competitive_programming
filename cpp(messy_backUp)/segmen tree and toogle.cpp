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
#define MAX 200010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct Node{
    LL lazy, val;
};

Node tree[4*MAX];


void update_node(int idx, int b, int e, LL v)
{
    if(v%2) cnd.val = ((e-b+1)-cnd.val);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    if(cnd.lazy!=0)
    {
        update_node(lnd, b, (b+e)>>1, cnd.lazy);
        update_node(rnd, ((b+e)>>1)+1, e, cnd.lazy);
    }
    cnd.lazy = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.val;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
    return lft+rgt;
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
    cnd.val = tree[lnd].val+tree[rnd].val;
}

int chi[MAX],tim,pos[MAX];
vector<int> mat[MAX];

int dfs(int p,int pa)
{
   pos[p]=tim++;
   FOR(i,0,(int)mat[p].size()-1)
   {
       int x=mat[p][i];
       if(x!=pa)dfs(x,p);
   }
   chi[p]=tim;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    tim=1;
    string str;
    int i,j,n,m,a,x,y,q;

    cin>>n;
    FOR(i,2,n)
    {
        cin>>a;
        mat[a].PB(i); mat[i].PB(a);
    }
    dfs(1,1);
    FOR(i,1,n)
    {
        cin>>a;
        x=pos[i];
        if(a>0)
        {
            update(1,1,MAX,x,x,1);
        }
        //cout<<query(1,1,MAX,x,x)<<' ';
    }
   // cout<<NL<<NL;

    cin>>q;
    FOR(i,1,q)
    {
        cin>>str;
        cin>>a;
        ///cout<<str<<NL;
        if(str=="get")cout<<query(1,1,MAX,pos[a],chi[a]-1)<<NL;
        else update(1,1,MAX,pos[a],chi[a]-1,1);
    }
    return 0;
}



