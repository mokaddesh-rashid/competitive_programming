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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

PR tree[4*MAX];

void update(int idx,int b,int e,int p,int v)
{
    if(p < b || e < p) return;
    if(b == e)
    {
        cnd = {v, v};
        return;
    }

    int mid = (b + e)>>1;

    update(lnd, b, mid, p, v);
    update(rnd, mid + 1, e, p, v);

    cnd.F = max(tree[lnd].F, tree[rnd].F);
    cnd.S = tree[lnd].S + tree[rnd].S;
}

int query(int idx,int b,int e,int p)
{
    if(p < b || e < p) return 0;
    if(e <= p) return cnd.S;

    int mid = (b + e)>>1;
    return query(lnd, b, mid, p) + query(rnd, mid + 1, e, p);
}

int finMax(int idx,int b,int e,int v)
{
    if(cnd.F < v) return -1;
    if(b == e) return b;

    int mid = (b + e)>>1;

    int ret = finMax(lnd, b, mid, v);
    if(ret != -1) return ret;

    return finMax(rnd, mid + 1, e, v);
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int n, q, v, p, val, cv;

    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> v;
        update(1, 1, MAX, i, v);
    }

    FOR(i,1,q)
    {
        cin >> p >> v;
        update(1, 1, MAX, p, v);

        int prin = -1;
        p = 0; val = query(1, 1, MAX, 1);

        while(p != -1)
        {
            p = finMax(1, 1, MAX, val);
            cout << val << ' ' << p << endl;
            if(p == -1) break;

            v = query(1, 1, MAX, p);
            cv = query(1, 1, MAX, p - 1); cv += cv;
            cout << v << "Dude " << ' ' << cv << endl;
            if(v == cv)
            {
                prin = p;
                break;
            }
            if(val == v) val++;
            else val = v;
        }

        cout << prin << endl;
    }

    return 0;
}
