#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define MAX 35005

struct Node
{
    int val;
    Node *lf, *rg;

    Node() {lf = rg = NULL; val = 0;}
};

void check(Node *idx)
{
    if(idx->lf == NULL)
    {
        idx->lf = new Node();
        idx->rg = new Node();
    }
}

void update(Node *idx, int b,int e,int p)
{
    if(b > p || p > e) return;
    if(b == e)
    {
        idx->val = 1;
        return;
    }

    check(idx);

    int m = (b + e)>>1;

    update(idx->lf, b, m, p);
    update(idx->rg, m + 1, e, p);

    idx->val = idx->lf->val + idx->rg->val;
}

void update(Node *oldIdx,Node *idx, int b,int e,int p)
{
    if(b > p || p > e) return;
    if(b == e)
    {
        idx->val = 1;
        return;
    }

    check(idx); check(oldIdx);

    int m = (b + e)>>1;

    if(b <= p && p <= m)
    {
        update(oldIdx->lf, idx->lf, b, m, p);
        idx->rg = oldIdx->rg;
    }
    else
    {
        update(oldIdx->rg, idx->rg, m + 1, e, p);
        idx->lf = oldIdx->lf;
    }

    idx->val = idx->lf->val + idx->rg->val;
}

int query(Node *idx, int b,int e,int l,int r)
{
    if(b > r || e < l) return 0;
    if(l <= b && e <= r) return idx->val;

    int m = (b + e)>>1, ret = 0;

    if(idx->lf != NULL) ret += query(idx->lf, b, m, l, r);
    if(idx->rg != NULL) ret += query(idx->rg, m + 1, e, l, r);

    return ret;
}



Node *Root[MAX];
int lasV[MAX], ara[MAX], go[MAX], n, col, up[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(i,0,MAX-1) Root[i] = new Node();

    cin >> n;
    FOR(i,1,n) cin >> ara[i];

    memset(lasV, -1, sizeof(lasV));
    REV(i,n,1)
    {
        go[i] = lasV[ ara[i] ];
        lasV[ ara[i] ] = i;
    }

    FOR(i,1,n)
        if(lasV[ ara[i] ] == i) update(Root[1], 0, MAX, i);

    FOR(i,2,n)
    {
        if(go[i - 1] == -1) Root[i] = Root[i - 1];
        else update(Root[i - 1], Root[i], 0, MAX, go[i-1]);
    }

    FOR(i,1,n)
    {
        int c = 0;
        FOR(j,i,n)
        {
            col++; c = 0;
            FOR(k,i,j)
            {
                c += (up[ ara[k] ] != col);
                up[ ara[k] ] = col;
            }
            if(c != query(Root[i], 0, MAX, i, j)) cout << i << ' ' << j << ' '  << endl;
        }
    }

    return 0;
}

