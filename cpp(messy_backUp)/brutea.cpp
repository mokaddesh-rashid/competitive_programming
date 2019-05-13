#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
#define MAX 500010
#define SZ 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL lft[MAX],rgt[MAX], ty[MAX], val[MAX], n,ase[MAX], tim[MAX];

struct node
{
    LL p,v;
};

class compare
{
    public:
        bool operator()( node f, node s )
        {
            return f.v < s.v;
        }

};
priority_queue< node, vector<node>, compare > que;

void bfs(LL p,LL v)
{
    node ol;
    ol.v=tim[p];
    ol.p=p;

    que.push(ol); ase[p]=v;
    LL a,b,c,d;

    while(!que.empty())
    {
        p=que.top().p; v=ase[p];
        cout<<p<<' '<<v<<NL;
        que.pop();
        val[p]+=v;
        ase[p]=0;

        a=lft[p]; b=rgt[p];
        c=v/2; d=v/2;
        if(v%2)
        {
            if(ty[p]%2==0) c++;
            else d++;
        }
        ol.p=a; ol.v=tim[a];
        if(a!=0&&ase[a]==0)que.push(ol);ase[a]+=c;
        ol.p=b; ol.v=tim[b];
        if(b!=0&&ase[b]==0)que.push(ol);ase[b]+=d;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    char ch;
    LL v;

    cin>>v>>n;
    FOR(i,1,n)
    {
      cin>>ch;
      if(ch=='L')ty[i]=0;
      else ty[i]=1;

      cin>>lft[i]>>rgt[i];
    }
    bfs(1,v);

    FOR(i,1,n)
    {
        if(val[i]%2) ty[i]=(ty[i]+1)%2;
        if(ty[i]==0)cout<<'L';
        else cout<<'R';
    }
    return 0;
}
