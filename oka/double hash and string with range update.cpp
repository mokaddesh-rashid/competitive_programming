#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define lnd (idx<<1)
#define rnd ((idx<<1) + 1)
#define Ba  23
#define M 141650939
#define MI 12317473
#define SO 1000000007
#define SI 739130440
#define LL long long
#define cnd tree[idx]
#define MAX 100010


typedef pair<LL,LL> PR;

string str;
pair<PR,LL> tree[MAX*4];
PR ran[MAX], mad[MAX];
int n;

PR ranHash(int l,int r)
{
    PR ret;

    ret.F = ran[r].F;
    if(l) ret.F += M, ret.F -= ran[l - 1].F;
    if(ret.F > M) ret.F -= M;

    ret.S = ran[r].S;
    if(l) ret.S += SO, ret.S -= ran[l - 1].S;
    if(ret.S > SO) ret.S -= SO;

    return ret;
}

void updateNode(int idx,int b,int e,int v)
{
    cnd.F = ranHash(b, e);

    cnd.F.F *= v; cnd.F.F %= M;
    cnd.F.S *= v; cnd.F.S %= SO;

    cnd.S = v;
}

void lazyUp(int idx,int b,int e)
{
    if(cnd.S != -1)
    {
        int mid = (b + e)>>1;
        updateNode(lnd, b, mid, cnd.S);
        updateNode(rnd, mid + 1, e, cnd.S);
    }
    cnd.S = -1;
}

void update(int idx,int b,int e,int st,int en,int v)
{
    if(st > e || en < b) return;
    if(st <= b && en >= e)
    {
        updateNode(idx, b, e, v);
        return;
    }

    lazyUp(idx, b, e);

    int mid = (b + e)>>1;

    update(lnd, b, mid, st, en, v);
    update(rnd, mid + 1, e, st, en, v);

    cnd.F.F = tree[lnd].F.F + tree[rnd].F.F; cnd.F.F %= M;
    cnd.F.S = tree[lnd].F.S + tree[rnd].F.S; cnd.F.S %= SO;
    return;
}

PR query(int idx,int b,int e,int st,int en)
{
    if(st > e || en < b) return make_pair(0, 0);
    if(st <= b && e <= en) return cnd.F;

    lazyUp(idx, b, e);
    int mid = (b + e)>>1;

    PR lft = query(lnd, b, mid, st, en);
    PR rgt = query(rnd, mid + 1, e, st, en);

    PR ret;
    ret.F = lft.F + rgt.F;
    ret.F %= M;

    ret.S = lft.S + rgt.S;
    ret.S %= SO;

    return ret;
}

int isSame(int l1,int r1,int l2,int r2)
{
    PR x, y;

    x = query(1, 1, n, l1, r1);
    x.F *= mad[l1].F; x.F %= M;
    x.S *= mad[l1].S; x.S %= SO;

    y = query(1, 1, n, l2, r2);
    y.F *= mad[l2].F; y.F %= M;
    y.S *= mad[l2].S; y.S %= SO;

    if(x != y) return 0;
    return 1;
}

void info()
{
    FOR(i,0,n)
    {
        if(i == 0) ran[i].F = Ba, mad[i].F = 1;
        else
        {
            ran[i].F = ran[i - 1].F * Ba; ran[i].F %= M;
            mad[i].F = mad[i - 1].F * MI; mad[i].F %= M;

            ran[i].S = ran[i - 1].S * Ba; ran[i].S %= SO;
            mad[i].S = mad[i - 1].S * SI; mad[i].S %= SO;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);
    int x, l, r, y, m, k, ty, c, d;

    cin >> n >> m >> k;
    info();
    cin >> str;

    FOR(i,0,n-1)
    {
        x = str[i] - '0';
        update(1, 1, n, i + 1, i + 1, x);
    }

    return 0;
}
