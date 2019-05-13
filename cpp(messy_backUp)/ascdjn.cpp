#include<bits/stdc++.h>

using namespace std;

#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 100010

long long tree[4*MAX];

void update(int idx,int b,int e,int p,int v)
{
    if(p > e || p < b ) return ;
    if(b == e)
    {
        tree[idx] += v;
        cout << p << ' ' << idx << ' ' << v << endl;
        return;
    }

    int mid = (b + e)>>1;
    update(lnd, b, mid, p, v);
    update(rnd, mid + 1, e, p, v);

    tree[idx] = max(tree[lnd], tree[rnd]);
}

long long query()
{
    return tree[1];
}


int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);

    int n, q, x, y;

    cin >> n;
    FOR(i,1,n) cin >> val[i];
    FOR(i,2,n)
    {
        x = i;
        cin >> y;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }

    dfs(1, 1);
    dsu(1, 1, 0);

    FOR(i,2,n) cout << prin[i] << endl;


    return 0;
}


