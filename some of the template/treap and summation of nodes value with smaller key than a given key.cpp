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

const LL MAX = (1e5) + 5;

struct Node
{
    LL key, prio, val, sum;
    Node *l, *r;

    Node(LL k,LL p,LL v)
    {
        key = k; prio = p; sum = val = v;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL gV(LL v = (1e9)) {return rng() % v;}

LL getSum(Node *t,LL low)
{
    if(t == NULL) return 0;

    if(t->key <= low)
    {
        LL ret = t->val;
        if(t->l != NULL) ret += t->l->sum;

        return getSum(t->r, low) + ret;
    }
    else return getSum(t->l, low);
}

vector<LL> getPer(LL N)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<LL> permutation(N);

    for (LL i = 0; i < N; i++)
        permutation[i] = i;

    shuffle(permutation.begin(), permutation.end(), rng);

    return permutation;
}
int main()
{
    ios::sync_with_stdio(false);
//    read;

    Node *R = NULL;
    LL n, k, v;

    cin >> n;
    vector<LL> id = getPer(n);

    LL l = 0;
    FOR(i,0,n-1)
    {
        cin >> k >> v;

        k ^= l; v = l ^ v;
        R = add(R, new Node(k, id[i], v));

        l = getSum(R, k);
        cout << k << ' ' << l << endl;
    }
    return 0;
}

