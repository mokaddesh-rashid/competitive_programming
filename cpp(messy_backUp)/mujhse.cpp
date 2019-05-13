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
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1005
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define LD long double
typedef pair<int,int> PR;

LL dp[MAX][10005], n;
struct node
{
    int s, w, v;
}ara[MAX];

LL rec(int p,int ba)
{
    if(p == n) return 0;

    LL &temp = dp[p][ba];
    if(temp != -1) return temp;

    temp = 0;
    if(ara[p].w <= ba)
    {
        int newBa = min(ara[p].s, ba - ara[p].w);
        temp = ara[p].v + rec(p + 1, newBa);
    }
    temp = max(temp, rec(p + 1, ba));

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL prin = 0;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i].w >> ara[i].s >> ara[i].v;
    sort(ara, ara + n, [](node x,node y){
            return x.s + x.w > y.w + y.s;
         });

    mem(dp, -1);
    FOR(i,0,n-1)
    {
        prin = max(prin, ara[i].v + rec(i + 1, ara[i].s));
    }
    cout << prin << endl;

    return 0;
}


