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

int rec(int b,int v)
{
    int cnt[11]={0};
    while(v>0)
    {
        int a=v%b;
        cnt[a]++;
        cnt[a]%=2;
        v/=b;
    }
    FOR(i,0,10)
    if(cnt[i]) return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,b,x,y,c;

    cin>>n;
    FOR(i,0,n-1)
    {
        c=0;
        cin>>b>>x>>y;

        FOR(i,1,y)
        {
            c=rec(b,i);
            cout<<i<<' ' <<c<<NL;
        }
    }
    return 0;
}

