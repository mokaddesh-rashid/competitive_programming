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
typedef pair<int,int> pr;

int pa[300010], m_s[300010], s[300010], wa;
struct node
{
    LL v, pa, l, la;
}dfa[300010];
vector<int> mat[300010];

void dfs(int p,int c)
{
    dfa[p].v = 1; pa[p]=c;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            dfs(x,c);
            if(dfa[p].l<=dfa[x].l) dfa[p].la=dfa[p].l,dfa[p].l=dfa[x].l;
            else dfa[p].la=max(dfa[p].la,dfa[x].l);
        }
    }
    dfa[p].l++;
    int a=dfa[p].l+dfa[p].la;
    wa=max(a,wa);
}

int rec(int p)
{
    if(p==pa[p]) return p;
    else return pa[p]=rec(pa[p]);
}
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, q, a, b, c, d, l, k;
    sfff(n,m,q);///cin>>n>>m>>q;
    FOR(i,0,m-1)
    {
        sff(a,b);///cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    FOR(i,1,n)
    {
        if(dfa[i].v==0)
        {
            wa=0;
            dfs(i,i);
            m_s[i]=(wa/2)+1;
            s[i]=wa;
            //cout<<i<<' '<<wa<<NL;
        }
    }
    FOR(i,1,q)
    {
        sf(c);///cin>>c;
        if(c==2)
        {
            sff(x,y);///cin>>x>>y;
            a=rec(x); b=rec(y);
            if(a!=b)
            {
                x=m_s[a]; y=m_s[b];
                //cout<<a<<' '<<b<<NL;
                if(x>y)
                {
                    pa[b]=a;
                    m_s[a]=max(x,y+1);
                    s[a]=max(s[a],x+y);
//                    cout<<a<<' '<<s[a]<<"   "<<m_s[a]<<NL;
                    //cout<<a<<NL;
                }
                else
                {
                   pa[a]=b;
                   m_s[b]=max(x+1,y);
                   s[b]=max(s[b],x+y);
//                   cout<<b<<' '<<s[b]<<"   "<<m_s[b]<<NL;
                  // cout<<b<<NL;
                }
            }
        }
        else
        {
            sf(x);///cin>>x;
            a=rec(x);
            pf("%d\n",s[a]-1);
        }
    }
    return 0;
}


