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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

LL dp[51][51], ret, ar[MAX], prin = 0;;
LL n, k;

LL ran(LL l,LL r)
{
    LL ret = ar[r];
    if(l) ret -= ar[l - 1];
    return ret;
}

LL rec(LL p,LL k)
{
    if(p == n && k != 0) return 0;
    if(p == n) return ret;
    if(k == 0) return 0;

    LL &temp = dp[p][k];
    if(temp != -1) return temp;

    temp = 0;
    FOR(i,p,n-1)
    {
        LL ans = (LL)ran(p, i) & rec(i + 1, k - 1);
        temp = max(temp, ans);
    }

    return temp;
}

LL cnt;
void rec(LL p,LL k,LL val)
{
    if(p == n && k != 0 && !cnt) return;
    cnt--;
    if(p == n)
    {
        prin = max(prin, val);
        return;
    }
    if(k == 0 || prin >= val) return;
    FOR(i,p,n-1-(k-1)+1)
        rec(i + 1, k - 1, val & ran(p, i));

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    ret = 0; cnt = 100000000;
    LL v = 1;
    for(LL i=0; i<=61; i++)
    {
        ret = ret + v;
        v *= 2;
        //cout << ret << endl << v << endl;
    }

    LL a, c = 0;
    cin >> n >> k;
    FOR(i,0,n-1)
    {
        cin >> a;
        c += a; ar[i] = c;
    }

    mem(dp, -1);
    prin = rec(0, k);
    rec(0, k, ret);

    cout << prin << endl;

    return 0;
}
