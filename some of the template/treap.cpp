#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef long long LL;
typedef pair<LL,LL> pii;

const LL MAX = (2e5) + 5;

struct Node
{
    LL key, prio, val, sum;
    Node *l, *r;

    Node(LL k,LL p)
    {
        key = k; prio = p; sum = val = 1;
        l = r = NULL;
    }
};

void update(Node *X)
{
    if(X == NULL) return;

    X->sum = X->val;
    if(X->l != NULL) X->sum += X->l->sum;
    if(X->r != NULL) X->sum += X->r->sum;

    return;
}

Node* leftRotate(Node *up,Node *down)
{
    up->l = down->r; down->r = up;
    update(down); update(up);
    return down;
}

Node* rightRotate(Node *up,Node *down)
{
    up->r = down->l; down->l = up;
    update(down); update(up);
    return down;
}

Node* balance(Node *R)
{
    if(R->l != NULL && R->l->prio < R->prio) return leftRotate(R, R->l);
    else if(R->r != NULL && R->r->prio < R->prio) return rightRotate(R, R->r);
    return R;
}

Node* add(Node* R,Node *org)
{
    if(R == NULL) return org;

    if(org->key <= R->key) R->l = add(R->l, org);
    else R->r = add(R->r, org);

    R = balance(R);
    update(R);
    return R;
}


Node* meld(Node *sm,Node *bg)
{
    if(sm == NULL) return bg;
    else if(bg == NULL) return sm;
    else if(sm->prio < bg->prio)
    {
        sm->r = meld(sm->r, bg);
        update(sm);
        return sm;
    }
    else
    {
        bg->l = meld(sm, bg->l);
        update(bg);
        return bg;
    }
}

Node* split(Node *R,int val) ///split treap with root R by value X to do it made node with value X my root
{
    if(R == NULL) return R;
    else if(R->key == val)
    {
        R->prio = -1;
        return R;
    }
    else if(R->key >= val) R->l = split(R->l, val);
    else R->r = split(R->r, val);

    R = balance(R);
    return R;

}

Node* eraseX(Node *R, int x) ///from treap with root R delete value X
{
    if(R == NULL) return R;

    R = split(R, x);

    if(R->key != x) return R;
    else if(R->l == NULL) return R->r;
    else if(R->r == NULL) return R->l;
    else return meld(R->l, R->r); /// now meld R->l and R->r and X will be deleted
}

int getSum(Node *t,int low)
{
    if(t == NULL) return 0;
    if(t->key <= low)
    {
        int ret = t->val;
        if(t->l != NULL) ret += t->l->sum;

        return getSum(t->r, low) + ret;
    }
    else return getSum(t->l, low);
}

map<int,int> mopa;
int getId(int p)
{
    if(mopa[p] == 0) mopa[p] = mopa.size();
    return mopa[p];
}

int main()
{
    ios::sync_with_stdio(false);
   // read;
    int n, q, v, u;

    cin >> n >> q;

    vector<int> ara(n + 1);
    vector<Node*> R(n + q, nullptr);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> per(n + q);
    for (int i = 0; i < n + q; i++)
        per[i] = i;
    shuffle(per.begin(), per.end(), rng);


    return 0;
}

