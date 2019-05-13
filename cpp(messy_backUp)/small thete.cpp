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
typedef pair<LL,int> PR;

map<PR,int> mopa;
LL n, l, r, lft[MAX], rgt[MAX], K, S;
vector<LL> daan[26];
vector<PR> baam;

LL fac(int i)
{
    if(i == 1) return 1;
    return fac( i - 1) * i;
}

void rec(int p,LL val,int cnt,int ty)
{
    if(p == -1)
    {
        ///cout << ty << ' ' << cnt << ' ' << val << endl;
        if(ty) baam.PB( MP(val, cnt) );
        else daan[cnt].PB( val );
        return;
    }

    LL add = rgt[p];
    if(ty) add = lft[p];

    rec(p - 1, val, cnt, ty);
    rec(p - 1, val + add, cnt, ty);
    if(add <= 19)  rec(p - 1, val + fac(add), cnt + 1, ty);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL prin = 0;

    cin >> n >> K >> S;
    l = n/2; r = n - l;

    FOR(i,0,l-1) cin >> lft[i];
    FOR(i,0,r-1) cin >> rgt[i];

    rec(l - 1, 0, 0, 1);
    rec(r - 1, 0, 0, 0);
    FOR(i,0,25) sort(daan[i].begin(), daan[i].end());

    FOR(k,0,K)
    {
        for(auto x : baam)
        {
            LL need = S - x.F, in = k - x.S;
            if(min(need, in) < 0) continue;

            int low = lower_bound(daan[in].begin(), daan[in].end(), need) - daan[in].begin();
            int up = upper_bound(daan[in].begin(), daan[in].end(), need) - daan[in].begin();

            prin += (up - low);
        }
    }

    cout << prin << endl;

    return 0;
}
