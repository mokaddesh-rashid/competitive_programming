#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
void make_unique(vector<int> &inii) {sort(inii.begin(), inii.end()); inii.resize(distance(inii.begin(), unique(inii.begin(), inii.end())));}

const int MAX = 100005;
static int id = 0;
struct Node
{
    int lft, rgt;
    int pref, suf, moa, len;

    Node()
    {
        len = lft = rgt = -1;
        pref = suf = moa = 0;
    }
}tree[4*MAX];

Node emp;

void mergeNode(Node &p,Node l,Node r)
{
    p.pref = l.pref; p.suf = r.suf;

    p.moa = max(l.moa, r.moa);
    p.moa = max(p.moa, l.suf + r.pref);

    if(l.pref == l.len) p.pref = l.len + r.pref;
    if(r.suf == r.len) p.suf = l.suf + r.len;

    p.moa = max(p.pref, p.moa); p.moa = max(p.suf, p.moa);
    return;
}

void update(int idx,int b,int e,int p,int v)
{
    if(tree[idx].len == -1) tree[idx].len = (e - b) + 1;

    if(p < b || e < p) return;
    if(b == e)
    {
        tree[idx].pref = tree[idx].suf = tree[idx].moa = v;
        return;
    }

    int m = (b + e)>>1;

    if(tree[idx].lft == -1) tree[idx].lft = id++;
    if(tree[idx].rgt == -1) tree[idx].rgt = id++;

    update(tree[idx].lft, b, m, p, v); update(tree[idx].rgt, m + 1, e, p, v);
    mergeNode(tree[idx], tree[ tree[idx].lft ], tree[ tree[idx].rgt ]);
}

Node query(int idx,int b,int e,int l,int r)
{
    if(l > e || r < b || idx == -1) return emp;
    if(l <= b && e <= r) return tree[idx];

    int m = (b + e)>>1;
    Node ans;
    mergeNode(ans, query(tree[idx].lft, b, m, l, r), query(tree[idx].rgt, m + 1, e, l, r));
    return ans;
}

int Root[MAX], ara[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    Node emp;
    int n;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];

    Root[0] = id++;
    FOR(i,0,n-1) update(Root[0], 0, n, i, ara[i]);

    return 0;
}
