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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


class compare
{
public:
    bool operator()(int x,int y)
    {
        return x>y;
    }
};
int in[sz],ans[sz];
set<int,compare>ms;
set<int>::iterator it;
vector<int> mat[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,d,p;

    cin>>n>>m;
    d=n;

    FOR(i,0,m-1)
    {
        cin>>a>>b;
        mat[b].PB(a);
        in[a]++;
    }

    FOR(i,1,n)
    {
        if(in[i]==0) ms.insert(i);
    }

    while(!ms.empty())
    {
        it=ms.begin();
        ms.erase(ms.begin());
        p=*it;
        ans[p]=d; d--;
        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            in[x]--;
            if(in[x]==0) ms.insert(x);
        }

    }

    FOR(i,1,n) cout<<ans[i]<<' ';
    return 0;
}
