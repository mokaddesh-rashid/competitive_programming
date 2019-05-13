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
#define MAX 2010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int stk[MAX],n,ar[MAX],cnt[MAX];

int chk(int v)
{
    multiset<int>ms;
    multiset<int>::iterator it;

    FOR(i,0,n-1) ms.insert(ar[i]);

    int x=1,a,b,c=0;
    while(!ms.empty())
    {
        it=ms.begin();
        ms.erase(it);
        a=*it; a+=v;
        it=ms.find(a);
        ///cout<<a-v<<' ';
        stk[c]=a;
        c++;
        if(it==ms.end()||*it!=a) return 0;
        ///cout<<*it<<NL;
        ms.erase(it);
    }

    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m;

    cin>>n; n*=2;
    FOR(i,0,n-1) cin>>ar[i];
    sort(ar,ar+n);

    FOR(i,1,n-1)
    {
        if(ar[i]-ar[0]>0&&chk(ar[i]-ar[0]))
        {
           n=n/2;
           FOR(j,0,n-1) cout<<stk[j]<<' ';
           return 0;
        }
       /// cout<<NL;
    }
    cout<<-1;
    return 0;
}


