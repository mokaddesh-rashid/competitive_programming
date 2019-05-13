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

struct node
{
    LL v, pa, l;
}dfa[100010];
vector<int> mat[100010], ole[MAX];
int va;

void dfs( int p )
{
    ole[va].PB(p);
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            dfa[x].l = dfa[p].l+1;
            dfa[x].pa = p;
            dfs(x);
        }
    }
}

pr ar[MAX];
int main()
{
    ios::sync_with_stdio(false);
   // inf;
   // outf;
    int tc=1;
    ///cin>>tc;

    FOR(tt,1,tc)
    {
        mem(dfa,0); va=0; clean(mat,100); clean(ole,100);
        int n,a,b,c=0,i,j;

        cin>>n;
        FOR(i,0,n-1) cin>>ar[i].F, ar[i].S=i;
        sort(ar,ar+n);

        FOR(i,0,n-1)
        {
            a=ar[i].S;
            mat[a].PB(i);
            mat[i].PB(i);
        }

        FOR(i,0,n-1)
        {
            a=ar[i].S;
            if(dfa[a].v==0) dfs(a), va++;
        }

        cout<<va<<NL;
        FOR(i,0,va-1)
        {
            cout<<ole[i].size()<<' ';
            sort(ole[i].begin(),ole[i].end());
            FOR(j,0,(int)ole[i].size()-1) cout<<ole[i][j]+1<<' ';
            cout<<NL;
        }
    }
    return 0;

}




