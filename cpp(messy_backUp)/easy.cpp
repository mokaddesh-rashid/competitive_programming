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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int n, k, cnt[MAX], bruh[MAX], val[MAX];
int dp[502][5010];

int rec(int p,int v)
{
    if(p == 0||v == 0) return 0;

    int &temp = dp[p][v];
    if(temp != -1) return temp;

    temp = 0;
    FOR(i,0,min(k,v))
    {
        temp = max(temp, rec(p - 1, v - i) + val[i]);
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int a, b = 0;

    cin >> n >> k;
    FOR(i,0,n*k-1)
    {
        cin >> a;
        cnt[a]++;
        b = max(b, a);
    }
    FOR(i,0,n-1)
    {
        cin >> a;
        bruh[a]++;
    }

    FOR(i,1,k) cin >> val[i];

    int prin = 0;

    mem(dp, -1);
    FOR(i,0,b)
        prin += rec(bruh[i], cnt[i]);

    cout << prin << endl;


    return 0;
}

