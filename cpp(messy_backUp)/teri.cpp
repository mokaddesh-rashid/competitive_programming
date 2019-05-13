#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
void make_unique(vector<int> &inii) {sort(inii.begin(), inii.end()); inii.resize(distance(inii.begin(), unique(inii.begin(), inii.end())));}

const int MAX = 200005;
static int id = 0;
struct Node
{
    int lft, rgt;
    int pref, suf, moa, len, b, e;

    Node()
    {
        e = lft = rgt = -1;
        b = pref = suf = moa = 0;
    }
}tree[10*MAX];

Node emp;

void mergeNode(Node &p,Node l,Node r)
{
    p.pref = l.pref; p.suf = r.suf;

    p.moa = max(l.moa, r.moa);
    p.moa = max(p.moa, l.suf + r.pref);

    if(l.pref == l.e - l.b + 1) p.pref = l.pref + r.pref;
    if(r.suf == r.e - r.b + 1) p.suf = l.suf + r.suf;

    p.moa = max(p.pref, p.moa); p.moa = max(p.suf, p.moa);
    return;
}

void update(int oldIdx,int idx,int b,int e,int p,int v)
{
    tree[oldIdx].b = tree[idx].b = b;
    tree[oldIdx].e = tree[idx].e = e;

    if(p < b || e < p) return;
    if(b == e)
    {
        tree[idx].pref = tree[idx].suf = tree[idx].moa = v;
        return;
    }

    int m = (b + e)>>1;

    tree[idx].lft = tree[oldIdx].lft;
    tree[idx].rgt = tree[oldIdx].rgt;

    if(b <= p && p <= m)
    {
        tree[idx].lft = id++;
        update(tree[oldIdx].lft, tree[idx].lft, b, m, p, v);
    }
    else
    {
        tree[idx].rgt = id++;
        update(tree[oldIdx].rgt, tree[idx].rgt, m + 1, e, p, v);
    }
    mergeNode(tree[idx], tree[ tree[idx].lft ], tree[ tree[idx].rgt ]);
}

Node query(int idx,int b,int e,int l,int r)
{
    tree[idx].b = b; tree[idx].e = e;

    if(l > e || r < b || idx == -1) return emp;
    if(l <= b && e <= r) return tree[idx];

    int m = (b + e)>>1;
    Node ans;
    mergeNode(ans, query(tree[idx].lft, b, m, l, r), query(tree[idx].rgt, m + 1, e, l, r));
    return ans;
}

int Root[MAX], ara[MAX], hei[MAX], p;

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    Node emp;
    int n, q, l, r, w;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];

    Root[n] = id++;

    FOR(i,0,n-1) hei[i]  = i;
    sort(hei, hei + n, [](int x,int y)
         {
            return ara[x] < ara[y];
         });

    REV(i,n-1,0)
    {
        Root[i] = id++;
        update(Root[i + 1], Root[i], 0, n, hei[i], 1);
    }

//    cin >> q;
//    FOR(oo,1,q)
//    {
//        cin >> l >> r >> w; l--; r--;
//        int st = 0, en = n - 1, prin = 0;
//
//        while(st <= en)
//        {
//            int mid = (st + en)>>1;
//
//            if(query(Root[mid], 0, n, l, r).moa >= w) st = mid + 1, prin = max(prin, mid);
//            else en = mid - 1;
//        }
//
//        cout << ara[ hei[prin] ] << endl;
//    }
    return 0;
}
