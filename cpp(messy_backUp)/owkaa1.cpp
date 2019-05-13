#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define sz 100010
typedef pair<int,int> pr;

struct info
{
    LL g,sg,cp,pa,mc,tc,l,co,go;  ///g=group, sg=start node of the group, cp=position in seg array, mc=max child, tc=total child in sub tree
    LL vis;
}dfa[100010];

struct node
{
    LL mx,sm,lazy,av;
}tree[4*sz];

vector<LL>mat[100010],cost[100010];
LL col,pos,ar[100010],n;


void init(LL idx, LL b, LL e )
{
    if( b == e )
    {
        cnd.mx = ar[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.mx=max(tree[lnd].mx,tree[rnd].mx);
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return minn;
    if(st <= b && en >= e)
        return cnd.mx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
}
void init2(LL idx, LL b, LL e )
{
    if( b == e )
    {
        cnd.mx = ar[b];
        return ;
    }
    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.mx=min(tree[lnd].mx,tree[rnd].mx);
    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

LL query2(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return minn;
    if(st <= b && en >= e)
        return cnd.mx;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return min(lft,rgt);
}

void dfs(LL p)
{
    dfa[p].vis=1;
    LL a,b,c,x,y,z;
    z=mat[p].size();
    FOR(i,0,z-1)
    {
        x=mat[p][i];
        if(dfa[x].vis==0)
        {
            dfa[x].l=dfa[p].l+1; dfa[x].pa=p; dfa[x].go=cost[p][i]; /// go saves cost from parent to child
            dfs(x);
            dfa[p].tc += dfa[x].tc; ///tc saves total child
            if(dfa[dfa[p].mc].tc < dfa[x].tc) dfa[p].mc=x, dfa[p].co=cost[p][i]; /// mc save maximum sized child and co save cost between mc and parent
        }
    }
    dfa[p].tc++;
}

void shit(LL p,LL st,LL val)
{
    dfa[p].vis=0;
    dfa[p].g=col; dfa[p].sg=st; dfa[p].cp=pos; ar[pos]=val; pos++;
    //cout<<val<<' ';
    if(dfa[p].mc==0) return;
    shit(dfa[p].mc,st,dfa[p].co);
}

LL fin_lca(LL a, LL b)
{
    LL x,y,z;
    x=dfa[a].sg; y=dfa[b].sg;
    if(dfa[a].g==dfa[b].g)
    {
        if(dfa[a].l<dfa[b].l)
        {
            z=query(1,1,n,dfa[a].cp+1,dfa[b].cp);
            return z;
        }
        z=query(1,1,n,dfa[b].cp+1,dfa[a].cp);
        return z;
    }
    if(dfa[x].l>dfa[y].l)
    {
        //cout<<dfa[x].cp+1<<' '<<dfa[a].cp<<NL;
        z=query(1,1,n,dfa[x].cp+1,dfa[a].cp);
        z=max(z,dfa[x].go);
        //cout<<z<<NL;
        return max(z,fin_lca(dfa[x].pa,b));
    }
    else
    {
        //cout<<dfa[y].cp+1<<' '<<dfa[b].cp<<NL;
        z=query(1,1,n,dfa[y].cp+1,dfa[b].cp);
        z=max(z,dfa[y].go);
        //cout<<z<<NL;
        return max(z,fin_lca(a,dfa[y].pa));
    }
}

string str;
pr con[100010];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        //mem(tree,0);
        mem(dfa,0);
        LL i,j,x,y,m,z,a,b,c;
        sf(n);///cin>>n;
        FOR(i,1,n) mat[i].clear(), cost[i].clear();
        FOR(i,1,n-1)
        {
            sfff(x,y,z);//cin>>x>>y>>z;
            con[i].F=x; con[i].S=y;
            mat[x].PB(y); mat[y].PB(x);
            cost[x].PB(z); cost[y].PB(z);
        }
        dfs(1); pos=col=1;
        FOR(i,1,n)
        {
           if(dfa[i].vis==1)
           {
               shit(i,i,0);
               col++;
           }
        }
        init(1,1,n);
        init2(1,1,n);
        sf(x);//cin>>x;
        FOR(i,0,x-1)
        {
            sff(a,b);//cin>>a>>b;
            y=query2(1,1,n,a,b);
            z=query(1,1,n,a,b);
            pf("%lld %lld",y,z);
        }
    }
    return 0;
}
