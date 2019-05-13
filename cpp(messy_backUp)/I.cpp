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
#define MAX 100010
#define MP  make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int cnt[MAX], col[MAX], n, c, l, M, r;
PR dude;
set<PR> sota;
set<PR>::iterator it;

int getVal(int u,int v)
{
    return abs(u - v) + 1;
}

int main()
{
    inf;
    ios::sync_with_stdio(false);
    int u, v, nc, cp, p, a, b, prin = 0;

    cin >> M >> c >> n;
    sota.insert( MP(M, 1) );
    cnt[1] = M;
    col[M] = 1;

    FOR(i,0,n-1)
    {
        cin >> p >> nc >> a >> b;
        int x = cnt[p];

        LL l = (a + (LL)x * x) % M;
        LL r = (a + (LL)(x + b) * (x + b)) % M;
        if(l > r) swap(l, r);
        l++; r++;

        while(true)
        {
            it = sota.lower_bound( MP(l, 0) );

            if(it == sota.end()) break;
            else dude = *it;

            u = dude.S; v = dude.F;

            if(u < l)
            {
                sota.erase( dude ); cp = col[v]; cnt[cp] -= getVal(u, v);

                sota.insert( MP(l - 1, u));
                cnt[cp] += getVal(u, l - 1);
                col[l - 1] = cp;

                if(v > r)
                {
                    sota.insert( MP(v, r + 1) );
                    cnt[cp] += getVal(v, r + 1);
                    col[v] = cp;
                }
            }
            else if(u >= l && u <= r)
            {
                sota.erase( dude );  cp = col[v]; cnt[cp] -= getVal(u, v);
                if(v > r)
                {
                    sota.insert( MP(v, r + 1) );
                    cnt[cp] += getVal(v, r + 1);
                    col[v] = cp;
                }
            }
            else break;
        }

        sota.insert( MP(r, l) );
        col[r] = nc;
        cnt[nc] += getVal(l, r);

    }

    FOR(i,1,c) prin = max(prin, cnt[i]);/// << endl;
    cout << prin << endl;

    return 0;
}
