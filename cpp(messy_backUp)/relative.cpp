#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i = j; i <= k; i++)
#define lnd (idx<<1)
#define rnd ((idx<<1) + 1)

const int MAX = 300010;

int tree[19][MAX], mbit[MAX], ara[MAX];


int n, k, cnt[MAX], sum[MAX];
long long prin;

int add(int l,int r)
{
    int m = r;
    if(l == r) return 0;
    if(l > r) swap(l, r);


    int v = ((k + sum[r]) - sum[l - 1]) % k;
    int vvv = ara[m] % k; v = (k + v - vvv) % k;
    return (v == 0);
}

vector<int> mat[1000005];

int getVal(int p,int l,int r)
{
    int low = lower_bound(mat[p].begin(), mat[p].end(), l) - mat[p].begin();
    int up = upper_bound(mat[p].begin(), mat[p].end(), r) - mat[p].begin();

    return up - low;
}

int boro(int x,int y) {return ara[x] >= ara[y] ? x : y;}
int query(int l,int r)
{
    int x = mbit[ (r - l) + 1 ];
    return boro(tree[x][l], tree[x][r - (1<<x) + 1]);
}

void divide(int b,int e)
{
    if(b > e) return;

    if(b == e) return;

    int m = query(b, e);
    int l1 = b, r1 = m - 1, l2 = m + 1, r2 = e;

    divide(l1, r1); divide(l2, r2);

    if(r1 - l1 < r2 - l2)
    {
        for(int i = l1; i <= m; i++)
        {
            int x = (sum[i - 1] + ara[m]) % k;
            prin += getVal(x, m, r2);
        }
    }
    else
    {
        for(int i = m; i <= r2; i++)
        {
            int x = (k + sum[i] - (ara[m] % k)) % k;
            prin += getVal(x, l1 - 1, m - 1);
        }
    }

    prin--;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);

    cin >> n >> k;
    FOR(i,1,n) cin >> ara[i];

    FOR(i,0,n) tree[0][i] = i;

    FOR(lev,1,18)
        FOR(i,0,n)
        {
            int pa = i + (1 << (lev - 1));
            tree[lev][i] = boro(tree[lev - 1][i], tree[lev - 1][pa]);
        }


    int p = 1;
    FOR(i,1,19)
    {
        int go = 1<<i;
        for(; p < go && p <= n; p++)
        {
            if(p == MAX) break;
            mbit[ p ] = i - 1;
        }
    }

    FOR(i,1,n) sum[i] = (ara[i] + sum[i - 1]) % k;
    FOR(i,0,n) mat[ sum[i] ].push_back( i );
    divide(1, n);

    cout << prin << endl;
    return 0;
}

