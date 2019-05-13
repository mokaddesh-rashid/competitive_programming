#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define LL long long
#define F first
#define S second
#define MAX 300010
#define MP make_pair

struct PR
{
    int f, s, p;
};

class Compare
{
public:
    bool operator()(PR x,PR y)
    {
        if(x.f == y.f) return x.s < y.s;
        else return x.f < y.f;
    }
};

PR ar[MAX];
int sfx[21][MAX];
string upor, niche, majhe, str;
int ara[MAX], brb[MAX], crc[MAX];
LL prin[MAX], M;

bool same(PR p,PR t)
{
    if(p.f == t.f && p.s == t.s) return 1;
    else return 0;
}

void sortSuffix(string str)
{
    int n = str.size();

    FOR(i,0,n-1) sfx[0][i] = str[i];

    FOR(i,1,20)
    {
        int x = 1<<(i - 1);
        FOR(j,0,n-1)
        {
            ar[j].f = sfx[i - 1][j];
            ar[j].s = -1;
            ar[j].p = j;

            if(j + x < n) ar[j].s = sfx[i - 1][j + x];
        }
        sort(ar, ar + n, Compare());

        int p = 0;
        FOR(j,0,n-1)
        {
            if(j != 0) if( !same(ar[j], ar[j - 1]) )p++;
            sfx[i][ ar[j].p ] = p;
        }
    }

    return;
}

pair<int,int> tree[4*MAX];

void update_node(int idx,int v)
{
    tree[idx] = max(tree[idx], MP(v, v));
}

void lazy_update(int idx)
{
    update_node(lnd, cnd.S);
    update_node(rnd, cnd.S);
    cnd.S = 0;
}

int query(int idx,int b,int e,int p)
{
    if(p > e || p < b) return 0;
    if(b == e) return cnd.F;

    lazy_update(idx);

    int mid = (b + e)>>1;
    return max( query(lnd, b, mid, p), query(rnd, mid + 1, e, p) );
}

void update(int idx,int b,int e,int st,int en,int v)
{
    if(st > e || en < b) return;
    if(st <= b && en >= e)
    {
        update_node(idx, v);
        return;
    }

    lazy_update(idx);

    int mid = (b + e)>>1;

    update(lnd, b, mid, st, en, v);
    update(rnd, mid + 1, e, st, en, v);

    tree[idx] = max(tree[lnd], tree[rnd]);
}

int lcp(int x,int y,int bs)
{
    if(bs == -1) return 0;

    int go = (1<<bs);

    if(max(x, y) + go <= str.size() && sfx[bs][x] == sfx[bs][y]) return go + lcp(x + go, y + go, bs);
    else return lcp(x, y, bs - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> upor >> majhe >> niche;
    str = upor + "0" + majhe + "1" + niche;
    sortSuffix( str );

    int n = str.size(), a, b, c;

    a = b = c = 0;
    FOR(i,0,n-1)
    {
        if(ar[i].p < upor.size()) a++;
        else if(ar[i].p < upor.size() + 1 + majhe.size()) b++;
        else c++;

        ara[i] = a; brb[i] = b; crc[i] = c;

    }

    FOR(i,0,n-1)
    {
        int p = ar[i].p;
        cout << p << " = ";
        FOR(j,p,n-1) cout << str[j];
        cout << endl;
    }
//
//    FOR(i,0,10000)
//    {
//        cin >> a >> b;
//        cout << lcp(a, b, 19) << endl;
//    }

    M = 1e9 + 7;
    FOR(i,0,n-1)
    {
        int v = query(1, 0, n, ar[i].p);

        int r = n - 1;
        while(i <= r)
        {
            int val = lcp(ar[i].p, ar[r].p, 19);
            ///if(val > v) break;

            int st = i, en = r, mid, l = r;

            while(st <= en)
            {
                mid = (st + en)>>1;
                if(ar[i].p == ar[mid].p || lcp(ar[i].p, ar[mid].p, 19) == val)
                    en = mid - 1, l = min(l, mid);
                else st = mid + 1;
            }

            a = ara[r]; b = brb[r]; c = crc[r];
            if(l) a -= ara[l - 1], b -= brb[l - 1], c -= crc[l - 1];

            LL x = (LL)a * b * c; x %= M;
            prin[val] += x; prin[val] %= M;
            cout << i << ' ' << val << ' ' << l << ' ' << r << endl;
            cout << a << ' ' << b << ' ' << c << endl;
            r = l - 1;
        }
        cout << endl;
        ///do update upore

    }

    int m = min(upor.size(), majhe.size());
    m = min(m, (int)niche.size());

    for(int i = m; i > 0; i--)
    {
        cout << prin[i] << ' ';
    }


    return 0;
}
