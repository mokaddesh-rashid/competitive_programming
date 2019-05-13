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

int tree[4*MAX], cnt[MAX];
int ex = MAX - 1;

void update(int idx,int b,int e,int p,int v)
{
    if(!(b <= p && p <= e)) return;
    if(b == e)
    {
        tree[idx] = p;
        cnt[p] = v;
        cout << "Added " << p << ' ' << v << endl;
        return;
    }

    int m = (b + e)>>1;
    update(lnd, b, m, p, v); update(rnd, m + 1, e, p, v);

    tree[idx] = tree[lnd];
    if(cnt[ tree[idx] ] < cnt[ tree[rnd] ]) tree[idx] = tree[rnd];
}

int query(int idx,int b,int e,int l,int r)
{
    if(b > r || e < l) return ex;
    if(l <= b && e <= r) return tree[idx];

    int m = (b + e)>>1;

    int lft = query(lnd, b, m, l, r), rgt = query(lnd, b, m, l, r);
    return cnt[lft] >= cnt[rgt] ? lft : rgt;
}

int isIncrease(vector<int> &vcc)
{
    int lp = -1;
    for(auto x : vcc)
    {
        if(lp >= x) return 0;
        lp = x;
    }
    return 1;
}

int isDecrease(vector<int> &vcc)
{
    int lp = MAX;
    for(auto x : vcc)
    {
        if(lp <= x) return 0;
        lp = x;
    }
    return 1;
}

vector<int> ckl, ckr;
int ara[MAX], nex[MAX], show[MAX], n;

int dec()
{
    mem(tree, 0); mem(cnt, 0); mem(nex, -1);
    REV(i,n-1,0)
    {
        int x = ara[i];
        int v = query(1, 0, MAX, 0, ara[i] - 1);
        update(1, 0, MAX, ara[i], cnt[v] + 1);
        cout << ara[i] << ":" << cnt[v] + 1 << ", ";
        nex[i] = v;
    }
    cout << endl;

    mem(show, 0); ckl.clear(); ckr.clear();
    int v = ara[0];
    FOR(i,0,n-1)
    {
        if(ara[i] == v)
        {
            show[i] = 1;
            ckl.PB( ara[i] );
            v = nex[i];
        }
        else
        {
            ckr.PB( ara[i] );
        }
    }

    return (isDecrease(ckl) && isIncrease(ckr));
}

int inc()
{
    mem(tree, 0); mem(cnt, 0); mem(nex, -1);
    REV(i,n-1,0)
    {
        int x = ara[i];
        int v = query(1, 0, MAX, ara[i] + 1, MAX - 1);
        update(1, 0, MAX, ara[i], cnt[v] + 1);
        cout << ara[i] << ":" << cnt[v] + 1 << ", ";
        nex[i] = v;
    }
    cout << endl;

    mem(show, 0); ckl.clear(); ckr.clear();
    int v = ara[0];
    FOR(i,0,n-1)
    {
        if(ara[i] == v)
        {
            show[i] = 1;
            ckl.PB( ara[i] );
            v = nex[i];
        }
        else
        {
            ckr.PB( ara[i] );
        }
    }

    return (isDecrease(ckl) && isIncrease(ckr));
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];
    cout << inc() << endl;
    return 0;
}

