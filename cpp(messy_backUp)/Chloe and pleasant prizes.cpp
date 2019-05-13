#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define PB push_back
#define LL long long
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define MAX 100010

int tree[4*MAX], lazy[4*MAX];

void update_node(int idx,int v)
{
    tree[idx] = lazy[idx] = v;
}

void update_lazy(int idx)
{
     if(lazy[idx])
     {
         update_node(lnd, lazy[idx]);
         update_node(rnd, lazy[idx]);
         lazy[idx] = 0;
     }
}

void update(int idx,int b,int e,int st,int en,int v)
{
    if(b > en || e < st) return;
    if(st <= b && e <= en)
    {
        update_node(idx, v);
        return;
    }

    update_lazy(idx);

    int m = (b + e)>>1;
    update(lnd, b, m, st, en, v);
    update(rnd, m + 1, e, st, en, v);
    tree[idx] = tree[lnd];
}

int query(int idx,int b,int e,int p)
{
    if(b > p || e < p) return 0;
    if(b == e) return tree[idx];

    update_lazy(idx);

    int m = (b + e)>>1;
    return max(query(lnd, b, m, p), query(rnd, m + 1, e, p));
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int val[MAX];

int main()
{
    ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int ty, u, l, r, v;

    FOR(oo,1,1000)
    {
        ty = (rng() % 2);
        if(ty)
        {
            u = (rng() % 10000) + 1;
            if(query(1, 1, MAX, u) != val[u])
                cout << "Fuck" << endl;
        }
        else
        {
            l = (rng() % 10000) + 1; r = (rng() % 10000) + 1;
            if(l > r) swap(l, r);

            v = (rng() % 10000) + 1;
            update(1, 1, MAX, l, r, v);
            FOR(i,l,r) val[i] = v;
        }
    }

    return 0;
}

